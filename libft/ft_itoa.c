/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:42:05 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/08 17:44:02 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_nb(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (i + 1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*resultat;
	int		i;
	long	nb;

	nb = n;
	i = len_nb(n);
	resultat = malloc(sizeof(char) * i + 1);
	if (!resultat)
		return (NULL);
	resultat[i] = '\0';
	i--;
	if (nb < 0)
	{
		resultat[0] = '-';
		nb *= -1;
	}
	if (n == 0)
		resultat[0] = '0';
	while (nb > 0)
	{
		resultat[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (resultat);
}
