/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_connecting_checking.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:16 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:36:12 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	is_map_connected_1(char *lines)
{
	int	i;

	i = 0;
	while (lines[i] != '\0')
	{
		if (lines[i] == '\n')
		{
			i++;
			while (lines[i] == ' ')
				i++;
			if (lines[i] == '\n')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

char	**create_copy_map(char **map, int row)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(sizeof(char *) * (row + 1));
	while (i < row)
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width
		|| map[y][x] == 'B' || map[y][x] == ' ')
		return ;
	map[y][x] = 'B';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

int	check_filled_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (map[i][j] == '0' || map[i][j] == '1')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_map_connected_2(t_game *game)
{
	char	**copy_map;

	copy_map = create_copy_map(game->map.map_2d, game->map.height);
	flood_fill(game, copy_map, game->loc_px, game->loc_py);
	if (check_filled_map(game, copy_map) == FALSE)
		return (free_double_pointer(copy_map), FALSE);
	free_double_pointer(copy_map);
	return (TRUE);
}
