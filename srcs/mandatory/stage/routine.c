/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:41 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:16:32 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	routine_start(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, TITLE);
	output_full_redraw(game);
	mlx_hook(game->win, 2, 0, keyboard_key_hook, game);
	mlx_hook(game->win, 17, 0, game_close, game);
	mlx_loop(game->mlx);
	return (0);
}

void	routine_end(t_game *game)
{
	game_d(game);
}
