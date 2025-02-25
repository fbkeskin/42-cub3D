/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:03 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/19 18:34:04 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	is_edge(int row, int column, t_game *game)
{
	if ((row == 0) || (column == 0) || (row == (game->map.height - 1))
		|| (column == (game->map.width - 1)))
		return (TRUE);
	return (FALSE);
}

int	is_valid_point(int row, int col, t_game *game)
{
	if ((row < 0 || row > (game->map.height - 1) || col < 0
			|| col > (game->map.width - 1)))
		return (FALSE);
	return (TRUE);
}

int	check_neighbours(char **map, int row, int col, t_game *game)
{
	int	col_offset;
	int	row_offset;

	row_offset = -1;
	while (row_offset <= 1)
	{
		col_offset = -1;
		while (col_offset <= 1)
		{
			if (is_valid_point((row + row_offset), (col + col_offset), game))
			{
				if (!(map[row + row_offset][col + col_offset] == ' ')
					&& !(map[row + row_offset][col + col_offset] == '1'))
					return (FALSE);
			}
			col_offset++;
		}
		row_offset++;
	}
	return (TRUE);
}

int	is_closed_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_edge(i, j, game))
			{
				if ((map[i][j] != '1') && (map[i][j] != ' '))
					return (FALSE);
			}
			if (((map[i][j] == ' ')) && (check_neighbours(map, i, j,
						game) == FALSE))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
