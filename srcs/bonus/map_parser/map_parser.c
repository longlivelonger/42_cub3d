/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:38:50 by zcris             #+#    #+#             */
/*   Updated: 2022/01/31 12:45:04 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	test_map_file(char *filename)
{
	int	fd;

	fd = -1;
	if (map_tests_is_cub(filename) == -1)
	{
		errors_print_ln(ERRORS_FILE_IS_NOT_CUB);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		errors_print(ERRORS_PREFIX);
		perror(filename);
		return (-1);
	}
	return (fd);
}

static void	map_parser_line_handling(t_game *game, char *str)
{
	char	*tmp;

	if (ft_strncmp("NO ", str, 3) == 0 && game->map->field->size == 0)
		game->checklist.no += texture_set_file(game->map->wall->no, str + 3);
	else if (ft_strncmp("SO ", str, 3) == 0 && game->map->field->size == 0)
		game->checklist.so += texture_set_file(game->map->wall->so, str + 3);
	else if (ft_strncmp("WE ", str, 3) == 0 && game->map->field->size == 0)
		game->checklist.we += texture_set_file(game->map->wall->we, str + 3);
	else if (ft_strncmp("EA ", str, 3) == 0 && game->map->field->size == 0)
		game->checklist.ea += texture_set_file(game->map->wall->ea, str + 3);
	else if (ft_strncmp("DO ", str, 3) == 0 && game->map->field->size == 0)
		texture_set_array_of_files(game->map->door, str + 3, DOOR_FRAME_COUNT);
	else if (ft_strncmp("F ", str, 2) == 0 && game->map->field->size == 0)
		game->checklist.f += str_to_color(game->map->floor->bgcolor, str + 2);
	else if (ft_strncmp("C ", str, 2) == 0 && game->map->field->size == 0)
		game->checklist.c += str_to_color(game->map->celling->bgcolor, str + 2);
	else
	{
		tmp = ft_strtrim(str, "\n");
		if (ft_strlen(tmp) == 0 && game->map->field->size > 0)
			game->checklist.no_empty_ln = 0;
		else if (ft_strlen(tmp) != 0)
			z_array_append(game->map->field, tmp);
		utls_free(tmp);
	}
}

static float	map_parser_get_player_angle_set(char c)
{
	if (c == 'N')
		return (3 * PI / 2);
	if (c == 'W')
		return (PI);
	if (c == 'S')
		return (PI / 2);
	return (0.0);
}

int	map_parser_get_player_position(t_game *game)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = -1;
	while (++y < (int)game->map->field->size)
	{
		x = -1;
		while (game->map->field->elem[y][++x])
		{
			if (found && ft_strchr("NSEW", game->map->field->elem[y][x]) != 0)
				return (0);
			if (ft_strchr("NSEW", game->map->field->elem[y][x]) != 0)
			{
				game->player->coords->dir = map_parser_get_player_angle_set(
						game->map->field->elem[y][x]);
				game->player->coords->x = x + 0.5;
				game->player->coords->y = y + 0.5;
				game->map->field->elem[y][x] = '0';
				found = 1;
			}
		}
	}
	return (found);
}

int	map_parser(t_game *game, char *filename)
{
	int		fd;
	char	*tmp;

	fd = test_map_file(filename);
	if (fd == -1)
		return (0);
	while (1)
	{
		tmp = utls_gnl(fd);
		if (NULL == tmp)
			break ;
		map_parser_line_handling(game, tmp);
		utls_free(tmp);
	}
	close(fd);
	utls_adjust_map_width(game);
	if (!map_tests_check(game))
		return (0);
	game_create_textures(game);
	return (1);
}
