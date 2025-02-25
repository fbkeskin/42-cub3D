/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:57:01 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:46:47 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"

/* EXTRA */
void	print_map(t_game *game);

/* UTILS */
void	print_error_message(char *message);
int		is_valid_path(char *path);
void	free_double_pointer(char **arr);
void	free_game_struct(t_game *game);
void	exit_game(t_game *game, char *message);
int		close_game(t_game *game);

/* MAP CHECK FUNCS*/
int		file_format_check(char *file_name, char type);
int		is_valid_type_identifier(char c1, char c2, char c3);
int		is_valid_path(char *path);
int		is_valid_rgb_channel(int *rgb_array);
void	digit_control(t_game *game, char **arr, char *data);
void	length_control(t_game *game, char **arr, char *data);

void	check_map(t_game *game);
int		is_closed_map(t_game *game, char **map);
int		is_map_connected_1(char *lines);
int		is_map_connected_2(t_game *game);

/* MAPP INITILIAZE FUNCS */
void	parse_map_file(t_game *game);
void	parse_elements(int i, int j, t_game *game);

/* game */
void	create_game_interface(t_game *game);
int		create_trgb(int t, int r, int g, int b);
void	move_on_direction_plane(t_game *game, int multiplier);
void	move_on_camera_plane(t_game *game, int multiplier);
void	rotate(t_game *game, int multiplier);
void	draw_background(int row, int column, t_game *game);
int		is_valid_rgb_channel(int *rgb_array);
void	calculate_side_distances(t_game *game);
void	init_raycast(t_game *game, int x);
void	perform_dda(t_game *game);
void	calculate_wall_height(t_game *game);
void	render_wall_slice(t_game *game, int x);
void	set_player_movement(t_game *game);
void	init_wall_surfaces(t_game *game);
void	init_floor_and_ceiling(t_game *game);
void	init_player(t_game *game);
void	init_player_2(t_game *game);
void	convert_xpm_to_img(t_game *game, int index, char *path);

#endif
