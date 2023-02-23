/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:56:19 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/21 16:54:52 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	util(t_parsing *data, t_child **child, pid_t pid_child)
{
	ft_lstadd_back_pipex(child, ft_lstnew_pipex(pid_child));
	if (dup2(data->fd[0], STDIN_FILENO) == -1 || close(data->fd[1]) == -1
		|| close(data->fd[0]) == -1)
		ft_exit(data, child, 0);
}

void	first_child(t_parsing *data, t_child **child)
{
	pid_t	pid_child;

	if (pipe(data->fd) == -1)
		ft_exit(data, child, 0);
	pid_child = fork();
	if (pid_child == 0)
	{
		if (data->first_fd == -1 || dup2(data->first_fd, STDIN_FILENO) == -1
			|| dup2(data->fd[1], STDOUT_FILENO) == -1 || close(data->fd[0])
			== -1 || close(data->fd[1]) == -1)
			ft_exit(data, child, 0);
		data->path = good_path(data->first_command[0], data->env_path);
		if (data->path == NULL)
			ft_exit(data, child, 127);
		else
		{
			if (execve(data->path, data->first_command, data->env) == -1)
				ft_exit(data, child, 127);
		}
	}
	else
		util(data, child, pid_child);
}

void	middle_child(t_parsing *data, t_child **child, int i)
{
	pid_t	pid_child;

	if (pipe(data->fd) == -1)
		ft_exit(data, child, 0);
	pid_child = fork();
	if (pid_child == 0)
	{
		if (dup2(data->fd[1], STDOUT_FILENO) == -1 || close(data->fd[0]) == -1
			|| close(data->fd[1]) == -1)
			ft_exit(data, child, 0);
		data->command = ft_split(data->argv[i], ' ');
		data->path = good_path(data->command[0], data->env_path);
		if (data->path == NULL)
			ft_exit(data, child, 127);
		else
		{
			if (execve(data->path, data->command, data->env) == -1)
				ft_exit(data, child, 127);
		}
	}
	else
		util(data, child, pid_child);
}

void	last_child(t_parsing *data, t_child **child)
{
	pid_t	pid_child;

	if (pipe(data->fd) == -1)
		ft_exit(data, child, 0);
	pid_child = fork();
	if (pid_child == 0)
	{
		if (data->last_fd == -1 || dup2(data->last_fd, STDOUT_FILENO) == -1
			|| close(data->fd[0]) == -1 || close(data->fd[1]) == -1)
			ft_exit(data, child, 0);
		data->path = good_path(data->last_command[0], data->env_path);
		if (data->path == NULL)
			ft_exit(data, child, 127);
		else
		{
			if (execve(data->path, data->last_command, data->env) == -1)
				ft_exit(data, child, 127);
		}
	}
	else
		util(data, child, pid_child);
}
