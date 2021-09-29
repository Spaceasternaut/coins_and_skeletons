/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:01:13 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/26 12:37:16 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_error_handler(int i)
{
	if (i == 1)
		printf("Error\nInconsistent map size.\n");
	else if (i == 2)
		printf("Error\nThe walls aren't placed correctly.\n");
	else if (i == 3)
		printf("Error\nInvalid character is present.\n");
	else if (i == 4)
		printf("Error\nWrong amount of players.\n");
	else if (i == 5)
		printf("Error\nThe map should have at least one exit.\n");
	else if (i == 6)
		printf("Error\nThe map should have at least one collectible.\n");
	else if (i == 7)
		printf("Error\nUse a valid .ber map as argument to start the game.\n");
	exit(-1);
}
