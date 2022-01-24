/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:38:41 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:08:03 by sbronwyn         ###   ########.fr       */
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
