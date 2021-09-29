/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:14 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:15 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **res, int n)
{
	while (n > 0)
	{
		n--;
		free(res[n]);
	}
	free(res);
}

static int	ft_wordcount(const char *str, char delim)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (*str != delim)
		{
			n++;
			while ((*str) && (*str != delim))
				str++;
		}
		else
			str++;
	}
	return (n);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while ((s[i]) && (s[i] != c))
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_strsplit(char **res, char const *s, char c, int n)
{
	int		word;
	int		i;
	int		j;

	word = 0;
	i = 0;
	while ((word < n) && (s[i]))
	{
		if (s[i] != c)
		{
			res[word] = malloc(ft_wordlen(s, c, i) + 1);
			if (res[word] == 0)
			{
				ft_free(res, word);
				return (0);
			}	
			j = 0;
			while ((s[i]) && (s[i] != c))
				res[word][j++] = s[i++];
			res[word][j] = '\0';
			word++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n;

	n = ft_wordcount(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (res == 0)
		return (0);
	res = ft_strsplit(res, s, c, n);
	if (!res)
		return (0);
	res[n] = 0;
	return (res);
}
