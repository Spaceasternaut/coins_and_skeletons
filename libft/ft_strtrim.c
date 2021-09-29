/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:57:45 by skaseltz          #+#    #+#             */
/*   Updated: 2021/08/27 13:57:46 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const s, char const *set)
{
	while (*set)
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = ft_strlen(s1) - 1;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_isset(s1[i], set) != 1)
			break ;
		i++;
	}
	while (j >= 0)
	{
		if (ft_isset(s1[j], set) != 1)
			break ;
		j--;
	}
	if (j < i)
		return (ft_strdup(""));
	return (ft_substr(s1, i, (j - i + 1)));
}
