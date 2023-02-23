/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:14:56 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/21 16:55:51 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**char_path(char **env, int j)
{
	char	**path;

	if (!env || !*env)
		return (NULL);
	while (env[j] && ft_strncmp(env[j], "PATH=", 5) != 0)
		j++;
	if (!env[j])
		return (NULL);
	path = ft_split2(env[j] + 5, ':');
	return (path);
}

int	cmd_ascii(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str && str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z'))
			res++;
		i++;
	}
	if (res > 0)
		return (1);
	return (0);
}

char	*good_path(char *cmd, char **path)
{
	int		i;
	char	*way;

	i = 0;
	if (cmd_ascii(cmd) == 0)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (path && path[i])
	{
		way = ft_strjoin(path[i], cmd);
		if (access(way, X_OK) == 0)
			return (free(way), ft_strjoin(path[i], cmd));
		i++;
		free(way);
	}
	return (NULL);
}

void	parsing(t_parsing *data)
{
	if (data->here_doc == 0)
	{
		data->first_fd = open(data->argv[1], O_RDONLY);
		data->last_fd = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	else
	{
		data->first_fd = open(".here_doc", O_RDONLY);
		data->last_fd = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	if (data->here_doc == 0)
		data->first_command = ft_split(data->argv[2], ' ');
	else
		data->first_command = ft_split(data->argv[3], ' ');
	data->last_command = ft_split(data->argv[data->argc - 2], ' ');
}
