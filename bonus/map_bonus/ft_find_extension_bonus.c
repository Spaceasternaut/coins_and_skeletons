/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_extension_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:15 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/22 15:24:03 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_find_extension(char *file, const char *extension)
{
	size_t		exlen;
	size_t		filelen;
	const char	*ptr;

	exlen = ft_strlen(extension);
	filelen = ft_strlen(file);
	ptr = &file[filelen - exlen];
	if (!ft_strncmp(ptr, extension, exlen))
	{
		return (0);
	}
	return (1);
}
