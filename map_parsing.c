/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:42:29 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:30:27 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	is_full_space(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	get_content(t_game *game, char **true_lines, int i, int line_counter)
{
	int		fd;
	char	*line;
	char	*lines;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		print_error_message("Invalid fd!");
	lines = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_full_space(line) == 0 || line_counter > 6)
		{
			lines = gnl_strjoin(lines, line);
			line_counter++;
		}
		free(line);
		i++;
	}
	close(fd);
	*true_lines = ft_strtrim(lines, WHITESPACE_ARR);
	free(lines);
}

void	get_map_size(t_game *game)
{
	int		i;
	size_t	max;
	char	**map;

	i = 0;
	map = &(game->file_content[6]);
	max = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if ((i > 0) && (ft_strlen(map[i]) > max))
			max = ft_strlen(map[i]);
		i++;
	}
	game->map.height = i;
	game->map.width = max;
}

void	parse_map_file(t_game *game)
{
	char	*lines;

	lines = NULL;
	get_content(game, &lines, 0, 0);
	if (lines == NULL)
		print_error_message("empty map");
	if (is_map_connected_1(lines) == FALSE)
		return (free(lines), print_error_message("Map is not connected."));
	game->file_content = ft_split(lines, '\n');
	free(lines);
	parse_elements(0, 0, game);
	if (game->file_content[6] == NULL)
		exit_game(game, "There is no map in the .cub file!");
	get_map_size(game);
	check_map(game);
}
