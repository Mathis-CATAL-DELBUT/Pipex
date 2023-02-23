/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:31:07 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/13 15:16:56 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_child	*ft_lstlast_pipex(t_child *lst)
{
	if (lst == NULL)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back_pipex(t_child **lst, t_child *new)
{
	t_child	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_pipex(*lst);
		last->next = new;
	}
}

t_child	*ft_lstnew_pipex(pid_t content)
{
	t_child	*tmp;

	tmp = malloc(sizeof(t_child));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
