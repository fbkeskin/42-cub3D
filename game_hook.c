/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:37:48 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:35:21 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	set_player_movement(t_game *game)
{
	if (game->keys.w)
		move_on_direction_plane(game, 1);
	if (game->keys.s)
		move_on_direction_plane(game, -1);
	if (game->keys.d)
		move_on_camera_plane(game, 1);
	if (game->keys.a)
		move_on_camera_plane(game, -1);
	if (game->keys.right)
		rotate(game, 1);
	if (game->keys.left)
		rotate(game, -1);
}

void	move_on_direction_plane(t_game *game, int multiplier)
{
	double	des_x;
	double	des_y;

	des_x = game->player.x + (game->player.dir_x * (double)1 / 50) * multiplier;
	des_y = game->player.y + (game->player.dir_y * (double)1 / 50) * multiplier;
	if (game->map.map_2d[(int)game->player.y][(int)des_x] != '1')
		game->player.x = des_x;
	if (game->map.map_2d[(int)des_y][(int)game->player.x] != '1')
		game->player.y = des_y;
}

void	move_on_camera_plane(t_game *game, int multiplier)
{
	double	des_x;
	double	des_y;

	des_x = game->player.x + game->player.plane_x * (double)1 / 50 * multiplier;
	des_y = game->player.y + game->player.plane_y * (double)1 / 50 * multiplier;
	if (game->map.map_2d[(int)game->player.y][(int)des_x] != '1')
		game->player.x = des_x;
	if (game->map.map_2d[(int)des_y][(int)game->player.x] != '1')
		game->player.y = des_y;
}

void	rotate(t_game *game, int multiplier)
{
	double	old_dirx;
	double	old_planex;
	double	rotate_angle;

	rotate_angle = 0.01 * multiplier;
	old_dirx = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotate_angle)
		- game->player.dir_y * sin(rotate_angle);
	game->player.dir_y = old_dirx * sin(rotate_angle) + game->player.dir_y
		* cos(rotate_angle);
	old_planex = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotate_angle)
		- game->player.plane_y * sin(rotate_angle);
	game->player.plane_y = old_planex * sin(rotate_angle) + game->player.plane_y
		* cos(rotate_angle);
}
