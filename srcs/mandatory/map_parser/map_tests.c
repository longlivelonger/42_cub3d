/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:51:56 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:05:11 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	map_tests_check_part2(t_game *game)
{
	if (!map_is_good_content(game))
	{
		errors_print_ln(ERRORS_BAD_MAP);
		return (0);
	}
	else if (!map_is_surrounded(game))
	{
		errors_print_ln(ERRORS_NOT_SURROUNDED);
		return (0);
	}
	return (1);
}

int	map_tests_check(t_game *game)
{
	if (!checklist_is_complete(game))
	{
		errors_print_ln(ERRORS_MISSED_INFO);
		return (0);
	}
	else if (game->map->field->size == 0)
	{
		errors_print_ln(ERRORS_EMPTY_MAP);
		return (0);
	}
	else if (!map_parser_get_player_position(game))
	{
		errors_print_ln(ERRORS_NO_PLAYER);
		return (0);
	}
	return (map_tests_check_part2(game));
}

int	map_is_surrounded(t_game *game)
{
	int	y;
	int	x;

	x = -1;
	while (game->map->field->elem[0][++x])
		if (game->map->field->elem[0][x] != '1')
			return (0);
	y = (int)game->map->field->size - 1;
	x = -1;
	while (game->map->field->elem[y][++x])
		if (game->map->field->elem[y][x] != '1')
			return (0);
	y = -1;
	while (++y < (int)game->map->field->size)
	{
		if (game->map->field->elem[y][0] != '1')
			return (0);
		x = (int)ft_strlen(game->map->field->elem[y]) - 1;
		if (game->map->field->elem[y][x] != '1')
			return (0);
	}
	return (1);
}

int	map_is_good_content(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)game->map->field->size)
	{
		x = -1;
		while (game->map->field->elem[y][++x])
		{
			if (game->map->field->elem[y][x] == ' ')
				game->map->field->elem[y][x] = '1';
			if (!map_tests_is_valid_char(game->map->field->elem[y][x]))
				return (0);
		}
	}
	return (1);
}
