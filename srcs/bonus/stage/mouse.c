/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:38:48 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	mouse_empty_hook(int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	(void)game;
	return (0);
}

static int	mouse_movement_hook(int x, int y, t_game *game)
{
	(void)y;
	if (x < WIDTH / 2)
		game->player->coords->dir -= 0.1;
	if (x > WIDTH / 2)
		game->player->coords->dir += 0.1;
	mlx_mouse_move(game->win, WIDTH / 2, HEIGHT / 2);
	output_full_redraw(game);
	return (0);
}

void	set_mouse_hook(t_game *game)
{
	mlx_mouse_move(game->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
	mlx_hook(game->win, 6, 0, mouse_movement_hook, game);
}

void	unset_mouse_hook(t_game *game)
{
	mlx_mouse_show();
	mlx_hook(game->win, 6, 0, mouse_empty_hook, game);
}
