/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:16 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:17 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (*s == (unsigned char)c)
	{
		ptr = (char *)s;
		return (ptr);
	}
	while (*s)
	{
		s++;
		if (*s == (unsigned char)c)
		{
			ptr = (char *)s;
			return (ptr);
		}
	}
	return (0);
}
