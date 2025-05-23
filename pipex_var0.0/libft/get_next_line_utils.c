/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:15:29 by rohta             #+#    #+#             */
/*   Updated: 2024/09/20 12:31:05 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_check(char *read_str, char *text, ssize_t i)
{
	free(read_str);
	if (i < 0)
		return (NULL);
	else
		return (text);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return ((size_t)(NULL));
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	while (*s && *s != uc)
		s++;
	if (*s == uc)
		return ((char *)(s));
	return (NULL);
}

static void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp_ch;
	char	*src_ch;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp_ch = (char *) dst;
	src_ch = (char *) src;
	if (dst <= src)
	{
		while (n--)
		{
			*tmp_ch++ = *src_ch++;
		}
	}
	else
	{
		tmp_ch += n;
		src_ch += n;
		while (n--)
		{
			*--tmp_ch = *--src_ch;
		}
	}
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	str_len1;
	size_t	str_len2;
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str_len1 = ft_strlen((char *)(s1));
	str_len2 = ft_strlen((char *)(s2));
	p = (char *)malloc(str_len1 + str_len2 + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s1, str_len1);
	ft_memmove(p + str_len1, s2, str_len2 + 1);
	return (p);
}
