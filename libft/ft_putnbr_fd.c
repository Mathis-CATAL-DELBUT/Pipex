/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:21:11 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/10/28 07:29:12 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nombre;

	nombre = n;
	if (nombre > 2147483647 || nombre < -2147483648)
		return ;
	if (nombre < 0)
	{
		nombre *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nombre > 9)
	{
		ft_putnbr_fd(nombre / 10, fd);
		ft_putchar_fd((nombre % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nombre + '0', fd);
}
