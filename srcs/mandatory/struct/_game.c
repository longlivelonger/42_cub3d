/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _game.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:35:17 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:09:14 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_close(void)
{
	exit (0);
}

t_game	*game_c(void)
{
	t_game	*game;

	game = utls_malloc(sizeof(t_game), 1);
	game->mlx = mlx_init();
	game->win = NULL;
	game->map = map_c();
	game->minimap = NULL;
	game->player = player_c();
	checklist_init(game);
	return (game);
}

void	game_d(t_game *game)
{
	player_d(game->player);
	map_d(game->map);
	if (NULL != game->win)
		mlx_destroy_window(game->map, game->win);
	utls_free(game->win);
	utls_free(game->mlx);
	utls_free(game);
}

static void	game_create_textures_part2(t_game *game)
{
	utls_mlx_create_solid_image(game, game->map->floor);
	utls_mlx_create_solid_image(game, game->map->celling);
}

void	game_create_textures(t_game *game)
{
	int	w;
	int	h;

	game->map->wall->no->mlx_img->img = mlx_xpm_file_to_image(
			game->mlx, game->map->wall->no->file_path, &w, &h);
	mlx_img_create_addrs(game->map->wall->no->mlx_img);
	game->map->wall->so->mlx_img->img = mlx_xpm_file_to_image(
			game->mlx, game->map->wall->so->file_path, &w, &h);
	mlx_img_create_addrs(game->map->wall->so->mlx_img);
	game->map->wall->we->mlx_img->img = mlx_xpm_file_to_image(
			game->mlx, game->map->wall->we->file_path, &w, &h);
	mlx_img_create_addrs(game->map->wall->we->mlx_img);
	game->map->wall->ea->mlx_img->img = mlx_xpm_file_to_image(
			game->mlx, game->map->wall->ea->file_path, &w, &h);
	mlx_img_create_addrs(game->map->wall->ea->mlx_img);
	game_create_textures_part2(game);
}
