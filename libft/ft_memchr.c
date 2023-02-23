/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:52:27 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/04 12:26:01 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *chaine, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	charactere;
	size_t			i;

	i = 0;
	str = (unsigned char *)chaine;
	charactere = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == charactere)
			return (str + i);
		i++;
	}
	return (NULL);
}
