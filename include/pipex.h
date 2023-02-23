/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:06:06 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/19 10:54:32 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct m_parsing
{
	int				first_fd;
	int				last_fd;
	int				here_doc_fd;
	int				fd[2];
	char			**first_command;
	char			**command;
	char			**last_command;
	char			*path;
	char			**env;
	char			**env_path;
	int				status;
	int				argc;
	char			**argv;
	char			*limiteur;
	int				here_doc;
}					t_parsing;

typedef struct m_child
{
	pid_t			content;
	struct m_child	*next;
}					t_child;

int					main(int argc, char **argv, char **env);
char				**char_path(char **env, int j);
char				*good_path(char *cmd, char **path);
void				parsing(t_parsing *data);
void				here_doc(t_parsing *data);

void				first_child(t_parsing *data, t_child **child);
void				middle_child(t_parsing *data, t_child **child, int i);
void				last_child(t_parsing *data, t_child **child);

void				free_all_tab(char **tab);
void				clean(t_parsing *data, t_child **child);
void				ft_exit(t_parsing *data, t_child **child, int error);
void				ft_error(t_parsing *data, int error);

t_child				*ft_lstlast_pipex(t_child *lst);
void				ft_lstadd_back_pipex(t_child **lst, t_child *new);
t_child				*ft_lstnew_pipex(pid_t content);

#endif