/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:48:33 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_coords	utls_next_cell(t_game *game, char direction)
{
	t_coords	result;
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;

	dir_x = cosf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	dir_y = sinf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	if (direction == 'd')
		dir_x *= -1;
	if (direction == 'd')
		dir_y *= -1;
	x = game->player->coords->x + dir_x;
	y = game->player->coords->y + dir_y;
	while ((int)x == (int)game->player->coords->x
		&& (int)y == (int)game->player->coords->y)
	{
		x += dir_x;
		y += dir_y;
	}
	result.x = x;
	result.y = y;
	return (result);
}
