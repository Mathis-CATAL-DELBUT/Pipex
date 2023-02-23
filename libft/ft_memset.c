/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:51:27 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/08 17:56:01 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*resultat;

	i = 0;
	resultat = (unsigned char *)b;
	while (i < len)
	{
		resultat[i] = c;
		i++;
	}
	return (resultat);
}
