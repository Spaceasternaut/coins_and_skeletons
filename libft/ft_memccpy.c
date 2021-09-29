/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:48 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:49 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	unsigned char	cc;

	psrc = (unsigned char *) src;
	pdst = (unsigned char *) dst;
	cc = (unsigned char) c;
	while (n > 0)
	{
		if (*psrc == cc)
		{
			*pdst = *psrc;
			return (++pdst);
		}
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (0);
}
