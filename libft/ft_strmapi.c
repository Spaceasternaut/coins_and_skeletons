/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:35 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:37 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	while (len--)
	{
		res[len] = f(len, s[len]);
	}
	return (res);
}
