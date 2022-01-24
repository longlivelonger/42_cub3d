/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:30:46 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	utls_mlx_pixel_put(t_mlx_img *t, int x, int y, t_color color)
{
	unsigned int	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = t->addr + (y * t->line_length + x * (t->bits_per_pixel / 8));
	*dst = utls_color_to_int(color);
}

void	utls_mlx_pixel_t_put(t_mlx_img *t, int x, int y, unsigned int pix)
{
	unsigned int	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = t->addr + (y * t->line_length + x * (t->bits_per_pixel / 8));
	*dst = pix;
}

unsigned int	utls_mlx_pixel_get_ys(t_mlx_img *t, int x, int y)
{
	unsigned int	*dst;
	unsigned int	result;

	if (x > 0)
		x -= 1;
	if (y > 0)
		y -= 1;
	dst = t->addr + (y * t->line_length + x * (t->bits_per_pixel / 8));
	result = *dst;
	return (result);
}

void	utls_mlx_image_put(t_mlx_img *t, int x, int y, t_mlx_img *s)
{
	unsigned int	*dst;
	unsigned int	*src;
	int				i;
	int				j;

	j = -1;
	while (++j < s->width)
	{
		i = -1;
		while (++i < s->height)
		{
			dst = t->addr + ((y + j) * t->line_length
					+ (x + i) * (t->bits_per_pixel / 8));
			src = s->addr + (j * s->line_length + i * (s->bits_per_pixel / 8));
			*dst = *src;
		}
	}
}

void	utls_mlx_create_solid_image(t_game *game, t_texture *t)
{
	int	i;
	int	j;

	t->mlx_img->img = mlx_new_image(game->mlx,
			t->mlx_img->width, t->mlx_img->height);
	mlx_img_create_addrs(t->mlx_img);
	j = -1;
	while (++j < t->mlx_img->height)
	{
		i = -1;
		while (++i < t->mlx_img->width)
			utls_mlx_pixel_put(t->mlx_img, i, j, *(t->bgcolor));
	}	
}
