/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _door.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:14:18 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_door	*door_c(void)
{
	t_door	*door;
	int		i;

	door = utls_malloc(sizeof(t_door), 1);
	i = -1;
	while (++i < DOOR_FRAME_COUNT)
		door->frames[i] = texture_c();
	door->current_frame = 0;
	return (door);
}

void	door_d(t_door *door)
{
	int		i;

	i = -1;
	while (++i < DOOR_FRAME_COUNT)
		texture_d(door->frames[i]);
	utls_free(door);
}
