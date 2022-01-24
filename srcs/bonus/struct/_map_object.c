/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:13:49 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map_object	*map_object_c(void)
{
	t_map_object	*map_object;

	map_object = utls_malloc(sizeof(t_map_object), 1);
	map_object->no = texture_c();
	map_object->so = texture_c();
	map_object->we = texture_c();
	map_object->ea = texture_c();
	return (map_object);
}

void	map_object_d(t_map_object *map_object)
{
	texture_d(map_object->ea);
	texture_d(map_object->we);
	texture_d(map_object->so);
	texture_d(map_object->no);
	utls_free(map_object);
}
