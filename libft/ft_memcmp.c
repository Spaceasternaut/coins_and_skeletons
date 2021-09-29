/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:51 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:51 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				res;
	unsigned char	*s1p;
	unsigned char	*s2p;

	res = 0;
	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	while (n-- && res == 0)
	{
		res = *s1p - *s2p;
		s1p++;
		s2p++;
	}
	return (res);
}
