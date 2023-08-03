/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:37:41 by sgluck            #+#    #+#             */
/*   Updated: 2023/07/17 12:36:12 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	check_input(argc, argv);
	map = malloc(sizeof (t_map));
	if (!map)
		begin_error("malloc map");
	map->map = NULL;
	game.map = map;
	game.filename = argv[1];
	init_game(&game);
	map_to_window(&game);
	ft_printf("\ndatamap: %s", game.map->map);
}
