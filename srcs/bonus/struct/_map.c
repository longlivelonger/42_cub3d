/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:50:01 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*map_c(void)
{
	t_map	*map;

	map = utls_malloc(sizeof(t_map), 1);
	map->floor = texture_c();
	map->celling = texture_c();
	map->wall = map_object_c();
	map->door = door_c();
	map->field = z_array_c();
	return (map);
}

void	map_d(t_map *map)
{
	z_array_d(map->field);
	door_d(map->door);
	map_object_d(map->wall);
	texture_d(map->celling);
	texture_d(map->floor);
	utls_free(map);
}
