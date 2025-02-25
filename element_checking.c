/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:30 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/24 15:11:07 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	is_valid_type_identifier_count(char c1, char c2, int floor, int ceiling)
{
	static int	north_count;
	static int	south_count;
	static int	west_count;
	static int	east_count;

	if (c1 == 'N' && c2 == 'O')
		north_count++;
	else if (c1 == 'S' && c2 == 'O')
		south_count++;
	else if (c1 == 'E' && c2 == 'A')
		east_count++;
	else if (c1 == 'W' && c2 == 'E')
		west_count++;
	else if (c1 == 'F')
		floor++;
	else if (c1 == 'N')
		ceiling++;
	if ((north_count > 1) || (south_count > 1) || (east_count > 1)
		|| (west_count > 1) || (floor > 1) || (ceiling > 1))
		return (FALSE);
	return (TRUE);
}

int	is_valid_type_identifier(char c1, char c2, char c3)
{
	static int	floor_count;
	static int	ceiling_count;

	if (!(is_valid_type_identifier_count(c1, c2, floor_count, ceiling_count)))
		return (FALSE);
	if (((c1 == 'N' && c2 == 'O') || (c1 == 'S' && c2 == 'O') || (c1 == 'E'
				&& c2 == 'A') || (c1 == 'W' && c2 == 'E'))
		&& (ft_isspace(c3) == 1))
		return (TRUE);
	else if ((c1 == 'F' || c1 == 'C') && (ft_strchr(WHITESPACE_ARR, c2) != 0))
		return (TRUE);
	return (FALSE);
}

int	is_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

void	digit_control(t_game *game, char **arr, char *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data[i] != '\n' && (ft_isspace(data[i]) == 1 || data[i] == ','
			|| ft_isdigit(data[i]) == 1))
	{
		if (data[i] == ',')
			count++;
		i++;
	}
	if (data[i] != '\0')
		return (free(data), free_double_pointer(arr), exit_game(game,
				"RGB channels contain only digits!"));
	if (count != 2)
		return (free(data), free_double_pointer(arr), exit_game(game,
				"RGB color array contains 3 channels!"));
}

void	length_control(t_game *game, char **arr, char *data)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	if (i != 3)
		return (free(data), free_double_pointer(arr), exit_game(game,
				"Wrong RGB channel count!"));
}
