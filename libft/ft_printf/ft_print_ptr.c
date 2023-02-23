/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:14:30 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/10 10:55:00 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_pointer(size_t pointer)
{
	char	string[20];
	int		i;
	int		longueur;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		ft_printstr("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	longueur = 2;
	while (pointer != 0)
	{
		string[i++] = base[pointer % 16];
		pointer = pointer / 16;
	}
	while (i--)
	{
		ft_printchar(string[i]);
		longueur ++;
	}
	return (longueur);
}
