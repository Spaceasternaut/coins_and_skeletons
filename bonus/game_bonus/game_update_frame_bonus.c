/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:29:01 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 15:09:31 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	game_update_frame(t_map *map)
{
	map->frame++;
	if (map->frame <= 40)
	{
		game_moving_coin(map);
		game_moving_skeleton(map);
		if (map->direction == 'L')
			game_moving_knight_left(map);
		else
			game_moving_knight_right(map);
	}
	else if (map->frame > 40)
		map->frame = 0;
	game_render_map(0, 0, map);
	return (0);
}

void	game_moving_coin(t_map *map)
{
	if (map->frame == 0)
		map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/coin-anim-1.xpm", &map->image_width, &map->image_height);
	if (map->frame == 10)
		map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/coin-anim-2.xpm", &map->image_width, &map->image_height);
	if (map->frame == 20)
		map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/coin-anim-3.xpm", &map->image_width, &map->image_height);
	if (map->frame == 30)
		map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/coin-anim-4.xpm", &map->image_width, &map->image_height);
	if (map->frame == 40)
		map->texture_coin = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/coin-anim-5.xpm", &map->image_width, &map->image_height);
}

void	game_moving_skeleton(t_map *map)
{
	if (map->frame == 0)
		map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/enemy-anim-1.xpm", &map->image_width, &map->image_height);
	if (map->frame == 10)
		map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/enemy-anim-2.xpm", &map->image_width, &map->image_height);
	if (map->frame == 20)
		map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/enemy-anim-3.xpm", &map->image_width, &map->image_height);
	if (map->frame == 30)
		map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/enemy-anim-4.xpm", &map->image_width, &map->image_height);
	if (map->frame == 40)
		map->texture_enemy = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/enemy-anim-5.xpm", &map->image_width, &map->image_height);
}

void	game_moving_knight_right(t_map *map)
{
	if (map->frame >= 0)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-r-1.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 10)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-r-2.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 20)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-r-3.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 30)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-r-4.xpm", &map->image_width, &map->image_height);
	if (map->frame == 40)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-r-5.xpm", &map->image_width, &map->image_height);
}

void	game_moving_knight_left(t_map *map)
{
	if (map->frame >= 0)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-l-1.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 10)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-l-2.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 20)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-l-3.xpm", &map->image_width, &map->image_height);
	if (map->frame >= 30)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-l-4.xpm", &map->image_width, &map->image_height);
	if (map->frame == 40)
		map->texture_player = mlx_xpm_file_to_image(map->mlx, \
		"imgs/bonus/knight-l-5.xpm", &map->image_width, &map->image_height);
}
