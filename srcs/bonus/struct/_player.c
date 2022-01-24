/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:38:41 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	*player_c(void)
{
	t_player	*player;

	player = utls_malloc(sizeof(t_player), 1);
	player->coords = coords_c();
	return (player);
}

void	player_d(t_player *player)
{
	coords_d(player->coords);
	utls_free(player);
}

void	player_into_minimap(t_game *game, t_mlx_img *mlximg)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->minimap->floor->mlx_img->width / 2;
	y = game->minimap->floor->mlx_img->height / 2;
	j = -1;
	while (++j < game->minimap->floor->mlx_img->height)
	{
		i = -1;
		while (++i < game->minimap->floor->mlx_img->width)
		{
			if (sqrt((i - x) * (i - x) + (j - y) * (j - y)) < x)
			{
				utls_mlx_pixel_put(mlximg,
					MINIMAP_POSITION_X
					+ 2 * x * (game->player->coords->x) - x + i,
					MINIMAP_POSITION_Y
					+ 2 * y * (game->player->coords->y) - y + j,
					*(game->minimap->player->bgcolor));
			}
		}
	}
}
