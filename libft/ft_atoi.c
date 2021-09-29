/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:56:17 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:56:19 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	flag;

	flag = 1;
	res = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -flag;
		str++;
	}
	while (*str && (*str >= 48) && ((*str <= 57)))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * flag);
}
