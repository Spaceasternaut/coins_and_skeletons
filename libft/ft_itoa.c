/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:46 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:47 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	long	a;
	int		i;
	char	*res;

	a = n;
	i = 0;
	size = ft_intlen(n);
	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		i++;
		a = -a;
	}
	while (size-- > i)
	{
		res[size] = (a % 10) + '0';
		a = a / 10;
	}
	return (res);
}
