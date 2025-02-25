/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:40:04 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:35:28 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	free_double_pointer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_elements(t_game *game)
{
	if (game->elements.north)
		free(game->elements.north);
	if (game->elements.south)
		free(game->elements.south);
	if (game->elements.west)
		free(game->elements.west);
	if (game->elements.east)
		free(game->elements.east);
}

void	free_images(t_game *game)
{
	if (game->img.north_texture)
		free(game->img.north_texture);
	if (game->img.south_texture)
		free(game->img.south_texture);
	if (game->img.east_texture)
		free(game->img.east_texture);
	if (game->img.west_texture)
		free(game->img.west_texture);
}

void	free_cub_surfaces(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->cub_surfaces[i].addr)
		{
			if (game->cub_surfaces[i].img)
				mlx_destroy_image(game->mlx, game->cub_surfaces[i].img);
		}
		i++;
	}
}

void	free_game_struct(t_game *game)
{
	free_elements(game);
	if (game->file_content)
		free_double_pointer(game->file_content);
	if (game->map.map_2d)
		free_double_pointer(game->map.map_2d);
	free_images(game);
	if (game->cub_surfaces->addr)
		free_cub_surfaces(game);
	if (game->mlx && game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	if (game->mlx_img)
		mlx_destroy_image(game->mlx, game->mlx_img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}
