/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:06:59 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/04 17:46:56 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	i = 0;
	while (dst[i] && i < dstsize)
	{
		i++;
	}
	dst_len = i;
	while ((src[i - dst_len] && i + 1 < dstsize))
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	if (dst_len < dstsize)
		dst[i] = '\0';
	return (dst_len + src_len);
}
