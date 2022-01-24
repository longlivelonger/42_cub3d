/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:41 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	routine_animation(t_game *game)
{
	static int	timer = 0;

	if (timer < 1000)
	{
		timer++;
		return (0);
	}
	timer = 0;
	game->map->door->current_frame = game->map->door->current_frame
		% (DOOR_FRAME_COUNT - 1) + 1;
	output_full_redraw(game);
	return (1);
}

int	routine_start(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, TITLE);
	output_full_redraw(game);
	mlx_hook(game->win, 2, 0, keyboard_key_hook, game);
	mlx_hook(game->win, 17, 0, game_close, game);
	set_mouse_hook(game);
	mlx_loop_hook(game->mlx, routine_animation, game);
	mlx_loop(game->mlx);
	return (0);
}

void	routine_end(t_game *game)
{
	game_d(game);
}
