/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _checklist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:24:08 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	checklist_init(t_game *game)
{
	game->checklist.no = 0;
	game->checklist.so = 0;
	game->checklist.we = 0;
	game->checklist.ea = 0;
	game->checklist.f = 0;
	game->checklist.c = 0;
}

int	checklist_is_complete(t_game *game)
{
	if (game->checklist.no == 1
		&& game->checklist.so == 1
		&& game->checklist.we == 1
		&& game->checklist.ea == 1
		&& game->checklist.f == 1
		&& game->checklist.c == 1)
		return (1);
	return (0);
}
