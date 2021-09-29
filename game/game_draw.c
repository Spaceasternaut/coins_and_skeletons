/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:48:37 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/22 15:16:39 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_initialize_images(t_map *map)
{
	map->texture_floor = mlx_xpm_file_to_image(map->mlx, \
	 "imgs/floor.xpm", &map->image_width, &map->image_height);
	map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
	"imgs/coin.xpm", &map->image_width, &map->image_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"imgs/exit-closed.xpm", &map->image_width, &map->image_height);
	map->texture_player = mlx_xpm_file_to_image(map->mlx, \
	"imgs/knight.xpm", &map->image_width, &map->image_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"imgs/wall.xpm", &map->image_width, &map->image_height);
	if (!map->texture_coin || !map->texture_exit || !map->texture_floor || \
	!map->texture_player || !map->texture_wall)
	{
		printf("Error\n .xpm file couldn't be read.\n");
		exit(-1);
	}
}

void	game_render_map(int i, int j, t_map *map)
{
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (map->field[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_wall, j * 64, i * 64);
			else if (map->field[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_floor, j * 64, i * 64);
			else if (map->field[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_player, j * 64, i * 64);
			else if (map->field[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_coin, j * 64, i * 64);
			else if (map->field[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
