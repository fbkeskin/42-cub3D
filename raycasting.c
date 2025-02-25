/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:55 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:36:17 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_raycast(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)SCREENWIDTH - 1;
	game->ray.raydir_x = game->player.dir_x + game->player.plane_x
		* game->ray.camera_x;
	game->ray.raydir_y = game->player.dir_y + game->player.plane_y
		* game->ray.camera_x;
	game->loc_px = (int)game->player.x;
	game->loc_py = (int)game->player.y;
	game->ray.deltadist_x = fabs(1 / game->ray.raydir_x);
	game->ray.deltadist_y = fabs(1 / game->ray.raydir_y);
	game->ray.hit_flag = 0;
}

void	calculate_side_distances(t_game *game)
{
	if (game->ray.raydir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.x - game->loc_px)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->loc_px + 1.0 - game->player.x)
			* game->ray.deltadist_x;
	}
	if (game->ray.raydir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.y - game->loc_py)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->loc_py + 1.0 - game->player.y)
			* game->ray.deltadist_y;
	}
}

void	perform_dda(t_game *game)
{
	while (game->ray.hit_flag == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->loc_px += game->ray.step_x;
			if (game->ray.step_x == 1)
				game->ray.hit_point = 1;
			else
				game->ray.hit_point = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->loc_py += game->ray.step_y;
			if (game->ray.step_y == 1)
				game->ray.hit_point = 2;
			else
				game->ray.hit_point = 3;
		}
		if (game->map.map_2d[game->loc_py][game->loc_px] == '1')
			game->ray.hit_flag = 1;
	}
}

double	calc_perp_dist_step(t_game *game)
{
	if (game->ray.hit_point == 0 || game->ray.hit_point == 1)
	{
		game->ray.perp_dist_step = (game->loc_px - game->player.x + (1
					- game->ray.step_x) / 2) / game->ray.raydir_x;
		if (game->ray.perp_dist_step <= 0.000001)
			game->ray.perp_dist_step = 0.00001;
		return (game->player.y + (game->ray.perp_dist_step
				* game->ray.raydir_y));
	}
	game->ray.perp_dist_step = (game->loc_py - game->player.y + (1
				- game->ray.step_y) / 2) / game->ray.raydir_y;
	if (game->ray.perp_dist_step <= 0.000001)
		game->ray.perp_dist_step = 0.00001;
	return (game->player.x + (game->ray.perp_dist_step * game->ray.raydir_x));
}

void	calculate_wall_height(t_game *game)
{
	double	wall_x;

	wall_x = calc_perp_dist_step(game);
	wall_x = wall_x - floor(wall_x);
	game->ray.wall_height = (SCREENHEIGHT / game->ray.perp_dist_step);
	game->ray.tex_x = (int)(wall_x * (double)TILE);
	if (game->ray.hit_point == 2 && game->ray.raydir_y > 0)
		game->ray.tex_x = 64 - game->ray.tex_x - 1;
	if (game->ray.hit_point == 0 && game->ray.raydir_x < 0)
		game->ray.tex_x = 64 - game->ray.tex_x - 1;
	game->ray.start_y = -game->ray.wall_height / 2 + SCREENHEIGHT / 2;
	if (game->ray.start_y < 0)
		game->ray.start_y = 0;
	game->ray.end_y = game->ray.wall_height / 2 + SCREENHEIGHT / 2;
	if (game->ray.end_y >= SCREENHEIGHT)
		game->ray.end_y = SCREENHEIGHT - 1;
}
