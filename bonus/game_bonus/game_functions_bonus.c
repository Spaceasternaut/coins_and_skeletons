/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:21:49 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 14:39:15 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	game_destroy_window(int keycode, t_map *map)
{
	if (keycode == ESC_BUTTON)
		mlx_destroy_window(map->mlx, map->mlx_win);
	printf("\nClosing the game...\n");
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC_BUTTON)
		game_destroy_window(ESC_BUTTON, map);
	if (keycode == A_BUTTON)
	{
		map->direction = 'L';
		game_steps(map, -1, 0);
	}
	if (keycode == S_BUTTON)
		game_steps(map, 0, 1);
	if (keycode == D_BUTTON)
	{
		map->direction = 'R';
		game_steps(map, 1, 0);
	}
	if (keycode == W_BUTTON)
		game_steps(map, 0, -1);
	return (0);
}

void	game_steps(t_map *map, int x, int y)
{
	if (map->field[map->y_player + y][map->x_player + x] != '1')
	{
		if (map->field[map->y_player + y][map->x_player + x] == 'C')
		{
			game_re_render_map(map, y, x);
			map->coins--;
			if (map->coins == 0)
				map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
				"imgs/exit-open.xpm", &map->image_width, &map->image_height);
		}
		else if (map->field[map->y_player + y][map->x_player + x] == 'E' \
		&& map->coins == 0)
		{
			game_re_render_map(map, y, x);
			game_end(map);
		}
		else if (map->field[map->y_player + y][map->x_player + x] == '0')
		{
			game_re_render_map(map, y, x);
		}
		else if (map->field[map->y_player + y][map->x_player + x] == 'S')
			game_over(map);
	}
	game_render_map(0, 0, map);
}

void	game_end(t_map *map)
{
	printf("\nYou win! Steps: %d\n", map->steps);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
}

void	game_re_render_map(t_map *map, int y, int x)
{
	map->steps++;
	map->field[map->y_player + y][map->x_player + x] = 'P';
	map->field[map->y_player][map->x_player] = '0';
	map->x_player = map->x_player + x;
	map->y_player = map->y_player + y;
	printf("Steps: %d\n", map->steps);
}
