/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:29 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/11 13:28:31 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlenchr(char const *s, char c)
{
	size_t	res;

	res = 0;
	if (!s)
		return (0);
	while (*s != c && *s != '\0')
	{
		res++;
		s++;
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlenchr(s1, '\0');
	len2 = ft_strlenchr(s2, '\0');
	len = len1 + len2;
	res = malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (len1-- > 0)
		*res++ = s1[i++];
	while (len2-- > 0)
		*res++ = *s2++;
	*res = '\0';
	res -= len;
	free((char *)s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = 0;
	if (!s)
		return (0);
	while (*s)
	{	
		if (*s == (unsigned char)c)
		{
			res = (char *)s;
			return (res);
		}
		s++;
	}
	if (*s == c)
		res = (char *)s;
	return (res);
}

void	ft_rewrite_buf(char **buf, int i)
{
	int	j;

	j = 0;
	while ((*buf)[i++])
		(*buf)[j++] = (*buf)[i];
}

char	*ft_check_buf(char *buf, char *line, int *flag_buf)
{
	int		i;
	char	*res;

	*flag_buf = 0;
	if (!*buf)
		return (0);
	if (!ft_strchr(buf, '\n'))
		return (ft_strjoin(line, buf));
	*flag_buf = 1;
	i = ft_strlenchr(buf, '\n');
	buf[i] = 0;
	res = ft_strjoin(line, buf);
	buf[i] = '\n';
	ft_rewrite_buf(&buf, i);
	return (res);
}
