/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:51 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/24 13:50:49 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	fill_rgb_array_2(t_game *game, char c, char *data)
{
	if (c == 'F')
	{
		if (is_valid_rgb_channel(game->elements.floor) == FALSE)
		{
			free(data);
			exit_game(game, "Invalid Floor RGB channel range!");
		}
	}
	if (c == 'C')
	{
		if (is_valid_rgb_channel(game->elements.ceiling) == FALSE)
		{
			free(data);
			exit_game(game, "Invalid Ceiling RGB channel range!");
		}
	}
}

void	fill_rgb_array(t_game *game, char c, char *data)
{
	char	**arr;

	arr = ft_split(data, ',');
	length_control(game, arr, data);
	digit_control(game, arr, data);
	if (c == 'F')
	{
		game->elements.floor[0] = ft_atoi(arr[0]);
		game->elements.floor[1] = ft_atoi(arr[1]);
		game->elements.floor[2] = ft_atoi(arr[2]);
	}
	else if (c == 'C')
	{
		game->elements.ceiling[0] = ft_atoi(arr[0]);
		game->elements.ceiling[1] = ft_atoi(arr[1]);
		game->elements.ceiling[2] = ft_atoi(arr[2]);
	}
	free_double_pointer(arr);
	fill_rgb_array_2(game, c, data);
}

void	create_element(t_game *game, char c, char *data)
{
	if (c == 'N')
		game->elements.north = ft_strdup(data);
	else if (c == 'S')
		game->elements.south = ft_strdup(data);
	else if (c == 'E')
		game->elements.east = ft_strdup(data);
	else if (c == 'W')
		game->elements.west = ft_strdup(data);
	else if (c == 'F' || c == 'C')
		fill_rgb_array(game, c, data);
	else
	{
		free(data);
		exit_game(game, "Missed or Invalid Element!");
	}
}

void	parse_elements(int i, int j, t_game *game)
{
	char	c1;
	char	c2;
	char	*data;
	char	c3;

	while (i < 6)
	{
		j = 0;
		while (ft_isspace(game->file_content[i][j]) == 1)
			j++;
		c1 = game->file_content[i][j];
		c2 = game->file_content[i][j + 1];
		c3 = game->file_content[i][j + 2];
		if (is_valid_type_identifier(c1, c2, c3) == FALSE)
			exit_game(game, "Element has incorrect type identifier!");
		data = ft_strtrim(&(game->file_content[i][j + 2]), WHITESPACE_ARR);
		if ((c1 != 'F' && c1 != 'C') && ((is_valid_path(data) == FALSE)
				|| (file_format_check(data, 'x') == FALSE)))
			return (free(data), exit_game(game, "Element has incorrect path!"));
		create_element(game, c1, data);
		free(data);
		i++;
	}
}
