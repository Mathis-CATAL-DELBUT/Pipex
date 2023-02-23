/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:15:44 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/22 11:58:06 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	call_child(t_parsing *data, t_child **child)
{
	int	i;

	if (data->here_doc == 0)
		i = 3;
	else
		i = 4;
	first_child(data, child);
	while (data->argc - i > 2)
	{
		middle_child(data, child, i);
		i++;
	}
	last_child(data, child);
}

void	here_doc(t_parsing *data)
{
	char	*str;
	char	*temp;

	data->first_fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	data->here_doc = 1;
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		temp = get_next_line(0);
		str = temp;
		if (!str || (ft_strncmp(str, data->argv[2],
					ft_strlen(data->argv[2])) == 0 && ft_strlen(str)
				- 1 == ft_strlen(data->argv[2])))
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(str, data->first_fd);
		free(temp);
	}
	close(data->first_fd);
}

int	main2(t_parsing *data, t_child **child)
{
	call_child(data, child);
	clean(data, child);
	if (errno == 9)
		errno = 0;
	if (data->here_doc == 1)
		unlink(".here_doc");
	if (WEXITSTATUS(data->status))
		errno = WEXITSTATUS(data->status);
	exit(errno);
}

int	main(int argc, char **argv, char **env)
{
	t_parsing	data;
	t_child		*child;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6))
		return (ft_putendl_fd("Error : Number arguments not correct\n", 2), 1);
	ft_memset(&data, 0, sizeof(data));
	child = NULL;
	data.argc = argc;
	data.argv = argv;
	data.path = NULL;
	data.env = env;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(&data);
	parsing(&data);
	data.env_path = char_path(env, 0);
	main2(&data, &child);
}
