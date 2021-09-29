/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:47 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:48 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			size;
	char			*res;

	size = 0;
	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	res = malloc(len + 1);
	if (!res)
		return (0);
	while (i < start && *s)
		i++;
	while (*s && size < len)
		res[size++] = s[i++];
	res[size] = '\0';
	return (res);
}
