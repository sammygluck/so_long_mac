/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5c_game_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:12:32 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/03 15:58:49 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	game_exit_success(game);
	return (0);
}

void	game_exit_success(t_game *game)
{
	game_exit(game);
	exit(EXIT_SUCCESS);
}

void	game_exit_failure(t_game *game, char *message)
{
	game_exit(game);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

int	game_exit(t_game *game)
{
	destroy_images(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	return (0);
}
