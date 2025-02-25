/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:40:55 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:36:01 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	map_has_possible_chars(t_game *game, int i, int j)
{
	while (game->file_content[i] != NULL)
	{
		j = 0;
		while (game->file_content[i][j] != '\0')
		{
			if (ft_strchr(MAP_CHARS, game->file_content[i][j]) == NULL)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	control_spawning_chars(t_game *game, int i, int j)
{
	int	counter;

	counter = 0;
	while (game->file_content[i] != NULL)
	{
		j = 0;
		while (game->file_content[i][j] != '\0')
		{
			if (ft_strchr(&(MAP_CHARS[3]), game->file_content[i][j]) != NULL)
			{
				game->player.direction = game->file_content[i][j];
				game->loc_px = j;
				game->loc_py = i - 6;
				counter++;
			}
			j++;
		}
		i++;
	}
	if (counter != 1)
		return (FALSE);
	return (TRUE);
}

void	create_completed_map_with_spaces(t_game *game, char **map)
{
	int	len;
	int	i;

	game->map.map_2d = (char **)malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.map_2d)
		exit_game(game, "Allocation Error!");
	game->map.map_2d[game->map.height] = NULL;
	i = 0;
	while (map[i] != NULL)
	{
		game->map.map_2d[i] = (char *)malloc(game->map.width + 1);
		game->map.map_2d[i][game->map.width] = '\0';
		if (!(game->map.map_2d[i]))
			exit_game(game, "Allocation Error!");
		len = ft_strlen(map[i]);
		game->map.map_2d[i] = ft_memcpy(game->map.map_2d[i], map[i], len);
		while (len < game->map.width)
		{
			game->map.map_2d[i][len] = ' ';
			len++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	if (map_has_possible_chars(game, 6, 0) == FALSE)
		exit_game(game,
			"The map must be composed of only possible characters!");
	if (control_spawning_chars(game, 6, 0) == FALSE)
		exit_game(game, "Incorrect counts of spawning characters!");
	create_completed_map_with_spaces(game, &(game->file_content[6]));
	if (is_closed_map(game, game->map.map_2d) == FALSE)
		exit_game(game, "Map is not closed!");
	if (is_map_connected_2(game) == FALSE)
		exit_game(game, "Map is not connected!");
}
