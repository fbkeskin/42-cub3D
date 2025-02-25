/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:57:10 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:34:45 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* LIBRARIES */
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* DEFINITIONS */
# define WHITESPACE_ARR " \t\n\v\f\r"
# define MAP_CHARS " 01NSWE"

# define TRUE 1
# define FALSE 0
# define PI 3.14
# define TILE 64

# define SCREENHEIGHT 1000
# define SCREENWIDTH 1500

# define CROSS 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 65363
# define LEFT 65361

/* STRUCTS */
typedef struct s_element
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor[3];
	int			ceiling[3];
}				t_element;

typedef struct s_map
{
	int			height;
	int			width;
	char		**map_2d;
}				t_map;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;

	int			step_x;
	int			step_y;
	int			hit_flag;
	int			hit_point;

	int			tex_x;
	int			tex_y;

	double		perp_dist_step;
	int			wall_height;
	int			start_y;
	int			end_y;
}				t_ray;

typedef struct s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_img
{
	void		*north_texture;
	void		*south_texture;
	void		*east_texture;
	void		*west_texture;
	int			floor_color;
	int			ceiling_color;
}				t_img;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		direction;
}				t_player;

typedef struct s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			right;
	int			left;
}				t_key;

typedef struct s_game
{
	char		*map_path;
	char		**file_content;

	int			loc_px;
	int			loc_py;

	void		*mlx;
	void		*mlx_window;
	void		*mlx_img;
	int			*img_buffer;
	int			bpp;
	int			line_length;
	int			endian;

	t_map		map;
	t_element	elements;
	t_img		img;
	t_player	player;
	t_data		cub_surfaces[4];
	t_key		keys;
	t_ray		ray;
}				t_game;

#endif
