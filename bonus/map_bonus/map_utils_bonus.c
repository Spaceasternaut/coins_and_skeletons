/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:00:03 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/26 12:29:39 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	map_initialize(t_map *map)
{
	map->length = 0;
	map->coins = 0;
	map->exit = 0;
	map->player = 0;
	map->x_player = 0;
	map->y_player = 0;
	map->height = 0;
	map->mlx = 0;
	map->steps = 0;
	map->frame = 0;
	map->direction = 'R';
}

int	map_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	map_fill(int fd, t_map *map)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &map->field[i]))
		i++;
	return (0);
}

void	map_valid_argument(t_map *map, int fd, char *argv)
{
	char	*line;
	int		i;

	i = 0;
	if (fd == -1)
	{
		perror("Error\n ::");
		exit (3);
	}
	while (get_next_line(fd, &line))
	{
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
	map->field = (char **)malloc(sizeof(char *) * map->height + 1);
	fd = open(argv, O_RDONLY);
	map_fill(fd, map);
	map_correct_format(map);
	map->height++;
}

int	map_correct_format(t_map *map)
{
	map->length = map_len(map->field[0]);
	map_check_consistency(map);
	map_check_wall(map, 0);
	map_check_content(map, 0, 0);
	return (0);
}
