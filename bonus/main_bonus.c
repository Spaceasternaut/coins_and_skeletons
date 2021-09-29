/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:02 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 14:43:50 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2 || ft_find_extension(argv[1], ".ber"))
		map_error_handler(7);
	fd = open(argv[1], O_RDONLY);
	map_initialize(&map);
	map_valid_argument(&map, fd, argv[1]);
	close(fd);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.length * IMG_SIZE, \
	map.height * IMG_SIZE, "Coins and skeletons");
	game_initialize_images(&map);
	game_render_map(0, 0, &map);
	mlx_loop_hook(map.mlx, &game_update_frame, &map);
	mlx_hook(map.mlx_win, 17, 0, game_destroy_window, &map);
	mlx_hook(map.mlx_win, 2, (1L << 0), key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
