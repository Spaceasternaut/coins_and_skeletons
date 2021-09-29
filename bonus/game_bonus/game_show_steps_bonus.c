/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_show_steps_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:45:04 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 15:05:56 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_show_steps_bonus(t_map *map)
{
	char	*res;

	res = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->mlx_win, 10, 20, 0xFFFF3333, "Steps: ");
	mlx_string_put(map->mlx, map->mlx_win, 70, 20, 0xFFFF3333, res);
	free(res);
}
