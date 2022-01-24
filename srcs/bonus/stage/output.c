/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:04:00 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 20:51:56 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	output_horizont(t_game *game, t_mlx_img *mlximg)
{
	int	i;
	int	j;

	j = 0;
	while (++j < WIDTH - 1)
	{
		i = -1;
		while (++i < HEIGHT / 2)
		{
			utls_mlx_pixel_put(mlximg, j, i, *(game->map->celling->bgcolor));
			utls_mlx_pixel_put(mlximg, j, HEIGHT / 2 + i,
				*(game->map->floor->bgcolor));
		}
	}
}

void	output_full_redraw(t_game *game)
{
	t_mlx_img	*mlximg;

	mlximg = mlx_img_c();
	mlximg->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_img_create_addrs(mlximg);
	output_horizont(game, mlximg);
	output_print_walls(game, mlximg);
	minimap_print_on_screen(game, mlximg);
	minimap_print_player_fov(game, mlximg);
	player_into_minimap(game, mlximg);
	mlx_put_image_to_window(game->mlx, game->win, mlximg->img, 0, 0);
	mlx_destroy_image(game->mlx, mlximg->img);
	utls_free(mlximg);
}

static t_mlx_img	*get_img(t_game *game, t_raycast_result *r)
{
	if (is_door(game, r) == 1)
		return (
			game->map->door->frames[0]->mlx_img);
	if (is_door(game, r) == 2)
		return (
			game->map->door->frames[game->map->door->current_frame]->mlx_img);
	else if (r->nsew == 1)
		return (game->map->wall->no->mlx_img);
	else if (r->nsew == 2)
		return (game->map->wall->so->mlx_img);
	else if (r->nsew == 3)
		return (game->map->wall->ea->mlx_img);
	else if (r->nsew == 4)
		return (game->map->wall->we->mlx_img);
	return (NULL);
}

static void	output_peace_of_wall(t_game *game, t_raycast_result *r,
									t_mlx_img *mlximg)
{
	int			j;
	int			x;
	int			h;
	t_mlx_img	*img;

	img = get_img(game, r);
	if (img == NULL)
		return ;
	h = (int)(HEIGHT / (float)r->distant);
	x = r->ray_number * (int)(WIDTH / (float)RAY_COUNT);
	j = -1;
	while (++j < h)
	{
		utls_mlx_pixel_t_put(mlximg, x, (HEIGHT / 2 - h / 2) + j,
			utls_mlx_pixel_get_ys(img, r->x_texture_position,
				j * (float)game->map->wall->we->mlx_img->height / h));
	}
}

void	output_print_walls(t_game *game, t_mlx_img *mlximg)
{
	t_raycast_result	r;

	r.ray_number = -1;
	while (++(r.ray_number) < RAY_COUNT)
	{
		r.x_texture_position = 0;
		r.nsew = 0;
		r.distant = 0;
		r.x_detect = game->player->coords->x;
		r.y_detect = game->player->coords->y;
		r.angle = game->player->coords->dir
			- PI / 6 + PI / 3 * r.ray_number / (float)RAY_COUNT;
		while (
			game->map->field->elem[(int)(r.y_detect)][(int)(r.x_detect)] == '0')
		{
			r.distant += 0.001;
			r.x_detect = game->player->coords->x + cosf(r.angle) * r.distant;
			r.y_detect = game->player->coords->y + sinf(r.angle) * r.distant;
		}
		r.distant *= cosf(r.angle - game->player->coords->dir);
		utls_ray_result(game, &r);
		if (r.ray_number > 0)
			output_peace_of_wall(game, &r, mlximg);
	}
}
