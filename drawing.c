/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:30:45 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/24 14:49:28 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	is_valid_rgb_channel(int *rgb_array)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 3)
	{
		if (rgb_array[i] < 0 || rgb_array[i] > 255)
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (FALSE);
	return (TRUE);
}

void	draw_background(int row, int column, t_game *game)
{
	while (row < (SCREENHEIGHT / 2))
	{
		column = 0;
		while (column < SCREENWIDTH)
		{
			game->img_buffer[(row * SCREENWIDTH)
				+ column] = game->img.ceiling_color;
			column++;
		}
		row++;
	}
	while (row < SCREENHEIGHT)
	{
		column = 0;
		while (column < SCREENWIDTH)
		{
			game->img_buffer[(row * SCREENWIDTH)
				+ column] = game->img.floor_color;
			column++;
		}
		row++;
	}
}

void	render_wall_slice(t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TILE / game->ray.wall_height;
	tex_pos = (game->ray.start_y - SCREENHEIGHT / 2 + game->ray.wall_height / 2)
		* step;
	i = game->ray.start_y;
	while (i <= game->ray.end_y)
	{
		tex_y = (int)tex_pos & 63;
		tex_pos += step;
		color = game->cub_surfaces[game->ray.hit_point].addr[(TILE * tex_y)
			+ game->ray.tex_x];
		game->img_buffer[i * SCREENWIDTH + x] = color;
		i++;
	}
}
