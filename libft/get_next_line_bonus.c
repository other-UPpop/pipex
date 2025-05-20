/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:42:57 by rohta             #+#    #+#             */
/*   Updated: 2024/11/13 15:11:57 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*aft_line(char *text)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (text[i] != '\0' && text[i] != '\n')
		++i;
	if (text[i] == '\0')
	{
		free (text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!str)
		return (NULL);
	++i;
	while (text[i])
		str[j++] = text[i++];
	str[j] = '\0';
	free (text);
	return (str);
}

static int	ft_n_check(char *text, char *str, size_t i)
{
	if (text[i] == '\n')
	{
		str[i] = '\n';
		++i;
	}
	return (i);
}

static char	*get_line(char *text)
{
	char	*str;
	size_t	i;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		++i;
	if (text[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
	{
		str[i] = text[i];
		++i;
	}
	i = ft_n_check(text, str, i);
	str[i] = '\0';
	return (str);
}

static char	*read_line(int fd, char *text)
{
	char	*read_str;
	char	*temp_str;
	ssize_t	i;

	read_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_str)
		return (NULL);
	i = 1;
	while (!ft_strchr(text, '\n'))
	{
		i = read(fd, read_str, BUFFER_SIZE);
		if (i <= 0)
			return (read_check(read_str, text, i));
		read_str[i] = '\0';
		temp_str = ft_strjoin(text, read_str);
		if (text)
			free (text);
		text = temp_str;
	}
	free (read_str);
	return (text);
}

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*text[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = read_line(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = get_line(text[fd]);
	text[fd] = aft_line(text[fd]);
	return (line);
}
