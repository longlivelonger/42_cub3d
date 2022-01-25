/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:16:06 by zcris             #+#    #+#             */
/*   Updated: 2022/01/25 16:46:28 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_angle(t_game *game, char direction)
{
	if (direction == 'l')
		return (game->player->coords->dir - (PI / 2));
	if (direction == 'r')
		return (game->player->coords->dir + (PI / 2));
	return (game->player->coords->dir);
}

static void	jump_through_portal(t_game *game, char direction, float x, float y)
{
	float	dir_x;
	float	dir_y;
	int		player_x;
	int		player_y;

	player_x = game->player->coords->x;
	player_y = game->player->coords->y;
	if (game->map->field->elem[(int)(player_y)][(int)(player_x)] == 'O')
		return ;
	dir_x = cosf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	dir_y = sinf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	while (game->map->field->elem[(int)(y)][(int)(x)] == 'O')
	{
		x += dir_x;
		y += dir_y;
	}
	if (game->map->field->elem[(int)(y)][(int)(x)] == '0')
	{
		game->player->coords->x = x;
		game->player->coords->y = y;
	}
}

static void	set_new_coords(t_game *game, char direction, float x, float y)
{
	t_coords	next_cell;

	next_cell = utls_next_cell(game, direction);
	if (!is_empty(
			game->map->field->elem[(int)(next_cell.y)][(int)(next_cell.x)]))
	{
		if (fabsf(next_cell.y - y) < 0.75 || fabsf(next_cell.x - x) < 0.75)
			return ;
	}
	if (game->map->field->elem[(int)(y)][(int)(x)] == '0')
	{
		game->player->coords->x = x;
		game->player->coords->y = y;
	}
	if (game->map->field->elem[(int)(y)][(int)(x)] == 'O')
		jump_through_portal(game, direction, x, y);
}

static void	keyboard_key_handling(t_game *game, char direction,
									float x, float y)
{
	float	dir_x;
	float	dir_y;

	if (direction == '<')
		game->player->coords->dir -= MOVEMENT_ROTATION_STEP;
	if (direction == '>')
		game->player->coords->dir += MOVEMENT_ROTATION_STEP;
	dir_x = cosf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	dir_y = sinf(get_angle(game, direction)) * MOVEMENT_STEP_MULTIPLIER;
	if (direction == 'u' || direction == 'l' || direction == 'r')
	{
		x = game->player->coords->x + dir_x;
		y = game->player->coords->y + dir_y;
	}
	if (direction == 'd')
	{
		x = game->player->coords->x - dir_x;
		y = game->player->coords->y - dir_y;
	}
	set_new_coords(game, direction, x, y);
}

int	keyboard_key_hook(int keycode, t_game *game)
{
	float	x;
	float	y;

	x = game->player->coords->x;
	y = game->player->coords->y;
	if (keycode == 46)
		unset_mouse_hook(game);
	if (keycode == 53)
		game_close();
	if (keycode == 13)
		keyboard_key_handling(game, 'u', x, y);
	if (keycode == 0)
		keyboard_key_handling(game, 'l', x, y);
	if (keycode == 2)
		keyboard_key_handling(game, 'r', x, y);
	if (keycode == 1)
		keyboard_key_handling(game, 'd', x, y);
	if (keycode == 123)
		keyboard_key_handling(game, '<', x, y);
	if (keycode == 124)
		keyboard_key_handling(game, '>', x, y);
	if (keycode == 14)
		toggle_door(game, x, y);
	output_full_redraw(game);
	return (0);
}
