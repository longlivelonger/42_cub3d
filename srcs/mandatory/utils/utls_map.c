/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:36:55 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/17 20:56:30 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_width(char **str, int count)
{
	char	*new_str;
	char	*filler;
	int		i;

	filler = utls_malloc(sizeof(*filler), count + 1);
	filler[count] = '\0';
	i = -1;
	while (++i < count)
		filler[i] = '1';
	new_str = ft_strjoin(*str, filler);
	if (new_str == NULL)
		return ;
	free(filler);
	free(*str);
	*str = new_str;
}

void	utls_adjust_map_width(t_game *game)
{
	int	y;
	int	x;
	int	max_width;

	max_width = 0;
	y = -1;
	while (++y < (int)game->map->field->size)
	{
		x = (int)ft_strlen(game->map->field->elem[y]);
		if (x > max_width)
			max_width = x;
	}
	y = -1;
	while (++y < (int)game->map->field->size)
	{
		x = (int)ft_strlen(game->map->field->elem[y]);
		if (x < max_width)
			fill_width(&game->map->field->elem[y], max_width - x);
	}
}
