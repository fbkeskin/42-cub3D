/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:38:08 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:41:34 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	convert_xpm_to_img(t_game *game, int index, char *path)
{
	t_data	*surfaces;

	surfaces = game->cub_surfaces;
	surfaces[index].img = mlx_xpm_file_to_image(game->mlx, path,
			&(surfaces[index].width), &(surfaces[index].height));
	if (!(surfaces[index].img))
		exit_game(game, "surface cannot initialized");
	surfaces[index].addr = (int *)mlx_get_data_addr(surfaces[index].img,
			&(surfaces[index].bits_per_pixel), &(surfaces[index].line_length),
			&(surfaces[index].endian));
	if (!(surfaces[index].addr))
		exit_game(game, "mlx image data cannot initialized");
}

int	release_key(int key_code, t_game *game)
{
	if (key_code == W)
		game->keys.w = 0;
	if (key_code == A)
		game->keys.a = 0;
	if (key_code == S)
		game->keys.s = 0;
	if (key_code == D)
		game->keys.d = 0;
	if (key_code == LEFT)
		game->keys.left = 0;
	if (key_code == RIGHT)
		game->keys.right = 0;
	return (0);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == ESC)
		close_game(game);
	if (key_code == W)
		game->keys.w = 1;
	if (key_code == A)
		game->keys.a = 1;
	if (key_code == S)
		game->keys.s = 1;
	if (key_code == D)
		game->keys.d = 1;
	if (key_code == LEFT)
		game->keys.left = 1;
	if (key_code == RIGHT)
		game->keys.right = 1;
	return (0);
}

int	game_handler(void *param)
{
	int		i;
	t_game	*game;

	game = (t_game *)param;
	i = 0;
	draw_background(0, 0, game);
	set_player_movement(game);
	while (i < SCREENWIDTH)
	{
		init_raycast(game, i);
		calculate_side_distances(game);
		perform_dda(game);
		calculate_wall_height(game);
		render_wall_slice(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->mlx_img, 0, 0);
	return (0);
}

void	create_game_interface(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_game(game, "mlx cannot initialized");
	game->mlx_window = mlx_new_window((game->mlx), SCREENWIDTH, SCREENHEIGHT,
			"cub3D");
	if (!(game->mlx_window))
		exit_game(game, "mlx window cannot initialized");
	game->mlx_img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!(game->mlx_img))
		exit_game(game, "mlx image cannot created");
	game->img_buffer = (int *)mlx_get_data_addr(game->mlx_img, &(game->bpp),
			&(game->line_length), &(game->endian));
	if (!(game->img_buffer))
		exit_game(game, "mlx image data cannot initialized");
	init_floor_and_ceiling(game);
	init_player(game);
	init_wall_surfaces(game);
	mlx_loop_hook(game->mlx, game_handler, game);
	mlx_hook(game->mlx_window, KEY_RELEASE, 1L << 1, release_key, game);
	mlx_hook(game->mlx_window, KEY_PRESS, 1L << 0, press_key, game);
	mlx_hook(game->mlx_window, CROSS, 1L << 0, close_game, game);
	mlx_loop(game->mlx);
}
