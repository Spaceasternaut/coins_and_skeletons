/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:55:43 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:28 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;
	size_t	len;

	res = 0;
	i = 0;
	len = ft_strlen(dst);
	if (size < len)
		res = size;
	else
		res = len;
	if ((size != 0) && len < size - 1)
	{
		while (src[i] && len < size - 1)
		{
			dst[len++] = src[i++];
			res++;
		}
		dst[len] = '\0';
	}
	while (src[i++])
		res++;
	return (res);
}
