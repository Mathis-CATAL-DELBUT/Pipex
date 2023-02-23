/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:13:00 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/21 13:24:34 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clean(t_parsing *data, t_child **child)
{
	t_child	*temp;

	close(data->fd[0]);
	close(data->fd[1]);
	while (*child)
	{
		temp = *child;
		waitpid((*child)->content, &data->status, 0);
		*child = (*child)->next;
		free(temp);
	}
	free(*child);
	free(data->path);
	free_all_tab(data->first_command);
	free_all_tab(data->last_command);
	free_all_tab(data->env_path);
	if (data->first_fd != -1)
		close(data->first_fd);
	if (data->last_fd != -1)
		close(data->last_fd);
}

void	ft_error(t_parsing *data, int error)
{
	if (error == 127)
	{
		if (data->first_fd != -1)
			close(data->first_fd);
		if (data->last_fd != -1)
			close(data->last_fd);
		ft_putendl_fd("Command not found", 2);
		exit(127);
	}
	if (errno != 0)
	{
		if (data->first_fd != -1)
			close(data->first_fd);
		if (data->last_fd != -1)
			close(data->last_fd);
		close(data->fd[0]);
		close(data->fd[1]);
		perror("Error ");
		exit(errno);
	}
}

void	ft_exit(t_parsing *data, t_child **child, int error)
{
	t_child	*temp;

	while (*child)
	{
		temp = *child;
		*child = (*child)->next;
		free(temp);
	}
	free(*child);
	free(data->path);
	free_all_tab(data->first_command);
	free_all_tab(data->last_command);
	free_all_tab(data->env_path);
	ft_error(data, error);
}
