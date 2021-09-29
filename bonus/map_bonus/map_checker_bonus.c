/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:00 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/22 16:32:43 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	map_check_consistency(t_map *map)
{
	int	i;
	int	current_length;

	i = 0;
	current_length = 0;
	while (i <= map->height)
	{
		current_length = map_len(map->field[i++]);
		if (map->length != current_length)
			map_error_handler(1);
	}
}

void	map_check_wall(t_map *map, int x)
{
	while (x < map->length)
	{
		if (map->field[0][x] != '1' || map->field[map->height][x] != '1')
			map_error_handler(2);
		x++;
	}
	x = 0;
	while (x <= map->height)
	{
		if (map->field[x][0] != '1' || map->field[x][map->length - 1] != '1')
			map_error_handler(2);
		x++;
	}
}

void	map_check_content(t_map *map, int i, int j)
{
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (map_check_char(map->field[i][j]) == -1)
				map_error_handler(3);
			if (map->field[i][j] == 'P')
			{
				map->x_player = j;
				map->y_player = i;
				map->player++;
			}
			else if (map->field[i][j] == 'C')
				map->coins++;
			else if (map->field[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	map_struct_check_amounts(map);
}

int	map_check_char(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E' && c != 'S')
		return (-1);
	return (0);
}

void	map_struct_check_amounts(t_map *map)
{
	if (map->player != 1)
		map_error_handler(4);
	if (map->exit == 0)
		map_error_handler(5);
	if (map->coins == 0)
		map_error_handler(6);
}
