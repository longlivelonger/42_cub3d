/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:46:01 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	toggle_door(t_game *game, float x, float y)
{
	t_coords	coords;

	coords = utls_next_cell(game, 'u');
	if (game->map->field->elem[(int)coords.y][(int)coords.x] == 'D')
	{
		game->map->field->elem[(int)coords.y][(int)coords.x] = 'O';
	}
	else if (game->map->field->elem[(int)coords.y][(int)coords.x] == 'O')
	{
		if (game->map->field->elem[(int)y][(int)x] == 'O')
			return ;
		game->map->field->elem[(int)coords.y][(int)coords.x] = 'D';
	}
}

int	is_no_door_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < DOOR_FRAME_COUNT)
	{
		if (game->map->door->frames[0]->file_path == NULL)
			return (1);
	}
	return (0);
}

int	is_empty(char c)
{
	if (c == '0' || c == 'O')
		return (1);
	return (0);
}

int	is_door(t_game *game, t_raycast_result *r)
{
	if (game->map->field->elem[(int)r->y_detect][(int)r->x_detect] == 'D')
		return (1);
	if (game->map->field->elem[(int)r->y_detect][(int)r->x_detect] == 'O')
		return (2);
	return (0);
}
