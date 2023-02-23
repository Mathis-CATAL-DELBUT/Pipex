/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:52:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/10/28 16:46:40 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chaine_1;
	const unsigned char	*chaine_2;
	size_t				i;

	i = 0;
	chaine_1 = (const unsigned char *)s1;
	chaine_2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (chaine_1[i] != chaine_2[i])
			return (chaine_1[i] - chaine_2[i]);
		i++;
	}
	return (0);
}
