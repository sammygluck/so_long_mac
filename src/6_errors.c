/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgluck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:17:52 by sgluck            #+#    #+#             */
/*   Updated: 2023/08/03 16:00:00 by sgluck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_error(t_map *map, char *string)
{
	free_map(map);
	ft_printf("Error\n%s\n", string);
	exit(EXIT_FAILURE);
}

void	begin_error(char *string)
{
	ft_printf("Error\n%s\n", string);
	exit(EXIT_FAILURE);
}
