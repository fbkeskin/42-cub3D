/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:27:43 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:48:02 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	game_init2(t_game *game)
{
	game->cub_surfaces[0].img = NULL;
	game->cub_surfaces[0].addr = NULL;
	game->cub_surfaces[1].img = NULL;
	game->cub_surfaces[1].addr = NULL;
	game->cub_surfaces[2].img = NULL;
	game->cub_surfaces[2].addr = NULL;
	game->cub_surfaces[3].img = NULL;
	game->cub_surfaces[3].addr = NULL;
	game->keys.a = 0;
	game->keys.w = 0;
	game->keys.d = 0;
	game->keys.s = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

void	game_init(t_game *game)
{
	game->file_content = NULL;
	game->loc_px = -1;
	game->loc_py = -1;
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->mlx_img = NULL;
	game->img_buffer = NULL;
	game->map.map_2d = NULL;
	game->player.direction = 'B';
	game->player.x = -1;
	game->player.y = -1;
	game->elements.north = NULL;
	game->elements.south = NULL;
	game->elements.east = NULL;
	game->elements.west = NULL;
	game->img.north_texture = NULL;
	game->img.south_texture = NULL;
	game->img.east_texture = NULL;
	game->img.west_texture = NULL;
	game_init2(game);
}

int	file_format_check(char *path, char type)
{
	size_t	len;

	len = ft_strlen(path);
	if (type == 'c')
	{
		if (len < 4 || ft_strncmp(".cub", &(path[len - 4]), 4) != 0)
			return (print_error_message("not cub file"), FALSE);
	}
	if (type == 'x')
	{
		if (len < 4 || ft_strncmp(".xpm", &(path[len - 4]), 4) != 0)
			return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error_message("The number of arguments must be 2!");
	file_format_check(argv[1], 'c');
	game.map_path = argv[1];
	game_init(&game);
	parse_map_file(&game);
	create_game_interface(&game);
	return (0);
}
