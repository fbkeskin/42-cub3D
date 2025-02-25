/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:25:44 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:27:11 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_player_2(t_game *game)
{
	if (game->player.direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (game->player.direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

void	init_player(t_game *game)
{
	game->player.x = (double)game->loc_px;
	game->player.y = (double)game->loc_py;
	if (game->player.direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	init_player_2(game);
}

void	init_wall_surfaces(t_game *game)
{
	convert_xpm_to_img(game, 0, game->elements.east);
	convert_xpm_to_img(game, 1, game->elements.west);
	convert_xpm_to_img(game, 2, game->elements.north);
	convert_xpm_to_img(game, 3, game->elements.south);
}

void	init_floor_and_ceiling(t_game *game)
{
	game->img.ceiling_color = create_trgb(255, game->elements.ceiling[0],
			game->elements.ceiling[1], game->elements.ceiling[2]);
	game->img.floor_color = create_trgb(255, game->elements.floor[0],
			game->elements.floor[1], game->elements.floor[2]);
}
