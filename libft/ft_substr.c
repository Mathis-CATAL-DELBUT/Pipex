/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:43 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/10 12:38:37 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*resultat;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen (s) - start;
	resultat = malloc(sizeof(char) * (len + 1));
	if (!resultat)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		resultat[j++] = s[i++];
	resultat[j] = '\0';
	return (resultat);
}
