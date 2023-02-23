/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:15:44 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:57 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main2(t_parsing *data, t_child **child)
{
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

	if (argc != 5)
		return (ft_putendl_fd("Error : Number arguments not correct\n", 2), 1);
	ft_memset(&data, 0, sizeof(data));
	child = NULL;
	data.path = NULL;
	data.env = env;
	data.argc = argc;
	data.argv = argv;
	parsing(&data);
	data.env_path = char_path(env, 0);
	if (pipe(data.fd) == -1)
		return (ft_exit(&data, &child, 0), 1);
	first_child(&data, &child);
	last_child(&data, &child);
	main2(&data, &child);
}
