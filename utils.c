/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:43:11 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 21:28:22 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	print_error_message(char *message)
{
	printf("Error\n");
	printf("%s", message);
	printf("\n");
	exit(1);
}

int	close_game(t_game *game)
{
	exit_game(game, NULL);
	exit(0);
}

void	exit_game(t_game *game, char *message)
{
	free_game_struct(game);
	if (message)
		print_error_message(message);
}
