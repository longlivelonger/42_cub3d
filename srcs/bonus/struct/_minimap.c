/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _minimap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:43:25 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_minimap	*minimap_c(void)
{
	t_minimap	*minimap;

	minimap = utls_malloc(sizeof(t_minimap), 1);
	minimap->wall = texture_c();
	minimap->floor = texture_c();
	minimap->player = texture_c();
	minimap->wall->mlx_img->width = MINIMAP_TEXTURE_WIDTH;
	minimap->wall->mlx_img->height = MINIMAP_TEXTURE_HEIGHT;
	minimap->floor->mlx_img->width = MINIMAP_TEXTURE_WIDTH;
	minimap->floor->mlx_img->height = MINIMAP_TEXTURE_HEIGHT;
	minimap->player->mlx_img->width = MINIMAP_TEXTURE_WIDTH;
	minimap->player->mlx_img->height = MINIMAP_TEXTURE_HEIGHT;
	str_to_color(minimap->wall->bgcolor, MINIMAP_COLOR_WALL);
	str_to_color(minimap->floor->bgcolor, MINIMAP_COLOR_FLOOR);
	str_to_color(minimap->player->bgcolor, MINIMAP_COLOR_PLAYER);
	minimap->fov_color = color_c(0, 0, 0);
	str_to_color(minimap->fov_color, MINIMAP_COLOR_FOV);
	minimap->door_color = color_c(0, 0, 0);
	str_to_color(minimap->door_color, MINIMAP_COLOR_DOOR);
	return (minimap);
}

void	minimap_d(t_minimap *minimap)
{
	color_d(minimap->door_color);
	color_d(minimap->fov_color);
	texture_d(minimap->player);
	texture_d(minimap->floor);
	texture_d(minimap->wall);
	utls_free(minimap);
}

void	minimap_print_on_screen(t_game *game, t_mlx_img *mlximg)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	x = MINIMAP_POSITION_X;
	y = MINIMAP_POSITION_Y;
	while (++i < (int)game->map->field->size)
	{
		j = -1;
		while (game->map->field->elem[i][++j])
		{
			if (!is_empty(game->map->field->elem[i][j]))
				utls_mlx_image_put(mlximg,
					x + j * game->minimap->wall->mlx_img->width,
					y + i * game->minimap->wall->mlx_img->height,
					game->minimap->wall->mlx_img);
			else if (game->map->field->elem[i][j] != ' ')
				utls_mlx_image_put(mlximg,
					x + j * game->minimap->floor->mlx_img->width,
					y + i * game->minimap->floor->mlx_img->height,
					game->minimap->floor->mlx_img);
		}
	}
}

void	minimap_print_player_fov(t_game *game, t_mlx_img *mlximg)
{
	t_coords	c;

	c.start = game->player->coords->dir - PI / 6;
	c.end = game->player->coords->dir + PI / 6;
	while (c.start <= c.end)
	{
		c.x = game->player->coords->x;
		c.y = game->player->coords->y;
		c.dir = c.start;
		while (is_empty(
				game->map->field->elem[(int)(c.y)][(int)(c.x)]))
		{
			utls_mlx_pixel_put(mlximg,
				MINIMAP_POSITION_X
				+ (c.x * game->minimap->floor->mlx_img->width),
				MINIMAP_POSITION_Y
				+ (c.y * game->minimap->floor->mlx_img->height),
				*(game->minimap->fov_color));
			c.x += cosf(c.dir) / 10;
			c.y += sinf(c.dir) / 10;
		}
		c.start += PI / 3 / RAY_COUNT;
	}
}
