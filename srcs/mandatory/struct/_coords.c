/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _coords.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:34:06 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_coords	*coords_c(void)
{
	t_coords	*coords;

	coords = utls_malloc(sizeof(t_coords), 1);
	coords->x = 0.0;
	coords->y = 0.0;
	coords->dir = 0.0;
	coords->start = 0.0;
	coords->end = 0.0;
	return (coords);
}

void	coords_d(t_coords *coords)
{
	utls_free(coords);
}
