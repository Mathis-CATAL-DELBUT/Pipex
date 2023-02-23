/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:30:50 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/21 10:55:13 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	size_t	stot_len;
// 	char	*rtn;

// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	s1_len = ft_strlen((char *)s1);
// 	s2_len = ft_strlen(s2);
// 	stot_len = s1_len + s2_len + 1;
// 	rtn = malloc(sizeof(char) * stot_len);
// 	if (!rtn)
// 		return (0);
// 	ft_memmove(rtn, s1, s1_len);
// 	ft_memmove(rtn + s1_len, s2, s2_len);
// 	rtn[stot_len - 1] = '\0';
// 	return (rtn);
// }

static size_t	ft_str_len(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		j;
	int		i;

	new = malloc(sizeof(char) * (ft_str_len(s1) + ft_str_len(s2) + 1));
	if (new)
	{
		j = 0;
		i = 0;
		while (s1 && s1[i])
			new[j++] = s1[i++];
		i = 0;
		while (s2 && s2[i])
			new[j++] = s2[i++];
		new[j] = '\0';
	}
	return (new);
}
