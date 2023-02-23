/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:39:39 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/10 12:44:28 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
