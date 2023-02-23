/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:11:02 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/06 14:40:36 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nombre_lettre2(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

static int	nombre_mots2(const char *str, char c)
{
	int	mots;
	int	sep;

	mots = 0;
	sep = 1;
	while (*str)
	{
		if (*str == c)
			sep = 1;
		else if (sep == 1)
		{
			mots++;
			sep = 0;
		}
		str++;
	}
	return (mots);
}

static char	**error(char **tab, int i)
{
	while (i < 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split2(const char *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (nombre_mots2(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (nombre_mots2(str, c))
	{
		while (*str && *str == c)
			str++;
		tab[i] = malloc(sizeof(char) * nombre_lettre2(str, c) + 2);
		if (!tab[i])
			return (error(tab, i));
		j = 0;
		while (*str && *str != c)
			tab[i][j++] = *str++;
		tab[i][j] = '/';
		tab[i++][j + 1] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
