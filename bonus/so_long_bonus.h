/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:38 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/24 14:38:20 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H
# define ESC_BUTTON 53
# define A_BUTTON 0
# define S_BUTTON 1
# define D_BUTTON 2
# define W_BUTTON 13
# define IMG_SIZE 64
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"
typedef struct s_map
{
	int		player;
	int		exit;
	int		length;
	int		height;
	char	**field;
	int		x_player;
	int		y_player;
	int		coins;
	void	*mlx;
	void	*mlx_win;
	void	*texture_floor;
	int		image_height;
	int		image_width;
	int		enemies;
	int		steps;
	void	*texture_wall;
	void	*texture_coin;
	void	*texture_exit;
	void	*texture_player;
	void	*texture_enemy;
	int		frame;
	char	direction;
}			t_map;

int		show_window(t_map *map);
int		ft_find_extension(char *file, const char *extension);
int		map_fill(int fd, t_map *map);
void	map_valid_argument(t_map *map, int fd, char *argv);
void	map_check_wall(t_map *map, int x);
int		map_correct_format(t_map *map);
int		map_len(char *str);
void	map_check_content(t_map *map, int i, int j);
void	map_check_consistency(t_map *map);
int		map_check_char(char c);
void	map_struct_check_amounts(t_map *map);
void	map_initialize(t_map *map);
void	map_error_handler(int i);
int		game_destroy_window(int keycode, t_map *map);
void	game_initialize_images(t_map *map);
void	game_render_map(int i, int j, t_map *map);
int		key_hook(int keycode, t_map *map);
void	game_steps(t_map *map, int x, int y);
void	game_end(t_map *map);
void	game_re_render_map(t_map *map, int y, int x);
void	game_show_steps_bonus(t_map *map);
void	game_put_sprite(int i, int j, t_map *map);
void	game_over(t_map *map);
int		game_update_frame(t_map *map);
void	game_moving_coin(t_map *map);
void	game_moving_skeleton(t_map *map);
void	game_moving_knight_left(t_map *map);
void	game_moving_knight_right(t_map *map);
#endif