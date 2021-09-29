/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:56 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:58 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	long			c;

	c = (long)count;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (dest - src <= c && dest > src)
		while (c--)
			pdest[c] = psrc[c];
	else
		ft_memcpy(dest, src, c);
	return (dest);
}
