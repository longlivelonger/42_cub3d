/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:29:09 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:33 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		errors_print_ln(ERRORS_SHELL_PARAMS);
		return (0);
	}
	game = game_c();
	if (!map_parser(game, argv[1]))
	{
		routine_end(game);
		return (0);
	}
	routine_start(game);
	routine_end(game);
	return (0);
}
