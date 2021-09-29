/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:38 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:39 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				res;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	i = 0;
	while (*s1p && *s2p && i < n)
	{
		res = *s1p - *s2p;
		if (res != 0)
			return (res);
		i++;
		s2p++;
		s1p++;
	}
	if (((*s1p == 0 && *s2p) || (*s1p && *s2p == 0)) && i < n)
		return (*s1p - *s2p);
	return (0);
}
