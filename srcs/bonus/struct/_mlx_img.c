/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:31 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_mlx_img	*mlx_img_c(void)
{
	t_mlx_img	*mlx_img;

	mlx_img = utls_malloc(sizeof(t_mlx_img), 1);
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	mlx_img->bits_per_pixel = 0;
	mlx_img->line_length = 0;
	mlx_img->endian = 0;
	mlx_img->width = 0;
	mlx_img->height = 0;
	return (mlx_img);
}

void	mlx_img_d(t_mlx_img *mlx_img)
{
	if (NULL != mlx_img->img)
		utls_free(mlx_img->img);
	if (NULL != mlx_img->addr)
		utls_free(mlx_img->addr);
	utls_free(mlx_img);
}

void	mlx_img_create_addrs(t_mlx_img *t)
{
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
			&t->line_length, &t->endian);
}
