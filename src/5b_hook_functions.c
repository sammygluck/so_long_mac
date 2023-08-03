/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5b_hook_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:11:18 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/03 14:26:25 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	if (get_value(game->map, x - 1, y) == '1')
		return ;
	else if (get_value(game->map, x - 1, y) == 'C')
		game->col.got += 1;
	else if (get_value(game->map, x - 1, y) == 'E')
	{
		if (game->col.got == game->col.total)
			win_game(game);
		else if (game->col.got != game->col.total)
			return ;
	}
	set_value(game->map, '0', x, y);
	set_value(game->map, 'P', x - 1, y);
	game->player.x_pos = x - 1;
	game->player.moves += 1;
	ft_printf("Total moves: %i\n", game->player.moves);
}

static void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	if (get_value(game->map, x + 1, y) == '1')
		return ;
	else if (get_value(game->map, x + 1, y) == 'C')
		game->col.got += 1;
	else if (get_value(game->map, x + 1, y) == 'E')
	{
		if (game->col.got == game->col.total)
			win_game(game);
		else if (game->col.got != game->col.total)
			return ;
	}
	set_value(game->map, '0', x, y);
	set_value(game->map, 'P', x + 1, y);
	game->player.x_pos = x + 1;
	game->player.moves += 1;
	ft_printf("Total moves: %i\n", game->player.moves);
}

static void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	if (get_value(game->map, x, y - 1) == '1')
		return ;
	else if (get_value(game->map, x, y - 1) == 'C')
		game->col.got += 1;
	else if (get_value(game->map, x, y - 1) == 'E')
	{
		if (game->col.got == game->col.total)
			win_game(game);
		else if (game->col.got != game->col.total)
			return ;
	}
	set_value(game->map, '0', x, y);
	set_value(game->map, 'P', x, y - 1);
	game->player.y_pos = y - 1;
	game->player.moves += 1;
	ft_printf("Total moves: %i\n", game->player.moves);
}

static void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x_pos;
	y = game->player.y_pos;
	if (get_value(game->map, x, y + 1) == '1')
		return ;
	else if (get_value(game->map, x, y + 1) == 'C')
		game->col.got += 1;
	else if (get_value(game->map, x, y + 1) == 'E')
	{
		if (game->col.got == game->col.total)
			win_game(game);
		else if (game->col.got != game->col.total)
			return ;
	}
	set_value(game->map, '0', x, y);
	set_value(game->map, 'P', x, y + 1);
	game->player.y_pos = y + 1;
	game->player.moves += 1;
	ft_printf("Total moves: %i\n", game->player.moves);
}

int	hook_actions(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 53)
		game_exit_success(game);
	if (game->col.total == game->col.got && !game->exit_open)
		open_exit(game);
	place_images(game, game->map);
	return (0);
}
