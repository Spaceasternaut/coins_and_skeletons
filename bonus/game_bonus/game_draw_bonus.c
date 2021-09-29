/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:48:37 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 15:11:45 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_initialize_images(t_map *map)
{
	map->texture_floor = mlx_xpm_file_to_image(map->mlx, \
	 "imgs/floor.xpm", &map->image_width, &map->image_height);
	map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
	"imgs/bonus/coin-anim-1.xpm", &map->image_width, &map->image_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"imgs/exit-closed.xpm", &map->image_width, &map->image_height);
	map->texture_player = mlx_xpm_file_to_image(map->mlx, \
	"imgs/bonus/knight-r-1.xpm", &map->image_width, &map->image_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"imgs/wall.xpm", &map->image_width, &map->image_height);
	map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
	"imgs/bonus/enemy-anim-1.xpm", &map->image_width, &map->image_height);
	if (!map->texture_coin || !map->texture_exit || !map->texture_floor || \
		!map->texture_player || !map->texture_wall || !map->texture_enemy)
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
			game_put_sprite(i, j, map);
			j++;
		}
		i++;
	}
	game_show_steps_bonus(map);
}

void	game_put_sprite(int i, int j, t_map *map)
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
	else if (map ->field[i][j] == 'S')
		mlx_put_image_to_window(map->mlx, map->mlx_win, \
		map->texture_enemy, j * 64, i * 64);
}
