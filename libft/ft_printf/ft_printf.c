/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:38:22 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/10 12:38:47 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_conversions(va_list args, const char conversions)
{
	int	print_length;

	print_length = 0;
	if (conversions == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (conversions == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (conversions == 'p')
		print_length += ft_pointer((size_t)va_arg(args, unsigned long long));
	else if (conversions == 'd' || conversions == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (conversions == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (conversions == 'x' || conversions == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), conversions);
	else if (conversions == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_conversions(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
