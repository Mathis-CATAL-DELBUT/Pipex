/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:02:07 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/02/19 10:39:04 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read(int fd, char *stash)
{
	int		n;
	char	*buf;

	n = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	while (n != 0 && !ft_strchr1(stash, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (free(buf), NULL);
		buf[n] = 0;
		stash = ft_strjoin1(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	new_stash = (char *)malloc(sizeof(char) * ft_strlen1(stash) - i + 1);
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
	new_stash[j] = 0;
	if (new_stash[0] == 0)
		return (free(stash), free(new_stash), NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read(fd, stash);
	if (!tmp)
		return (NULL);
	stash = tmp;
	tmp = ft_line(stash);
	if (!tmp)
		return (free(stash), NULL);
	line = tmp;
	stash = ft_new_stash(stash);
	if (line[0] == 0)
		return (free(stash), free(line), NULL);
	return (line);
}
