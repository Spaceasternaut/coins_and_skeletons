/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:49 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:50 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*res;

	ptr = (unsigned char *)s;
	res = NULL;
	while (n--)
	{
		if (*ptr != (unsigned char)c)
			ptr++;
		else
		{
			res = ptr;
			return (res);
		}
	}
	return (res);
}
