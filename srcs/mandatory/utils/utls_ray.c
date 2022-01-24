/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:26:27 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_nsew(float x, float y)
{
	float	diff_x;
	float	diff_y;
	int		nsew;

	nsew = 0;
	diff_x = x - (int)x;
	diff_y = y - (int)y;
	if (diff_y > 0.999)
		nsew = 2;
	if (diff_y < 0.001)
		nsew = 1;
	if (nsew != 0 && diff_x < 0.001)
		nsew = -1;
	if (nsew == 0 && diff_x < 0.001)
		nsew = 4;
	if (nsew != 0 && diff_x > 0.999)
		nsew = -1;
	if (nsew == 0 && diff_x > 0.999)
		nsew = 3;
	return (nsew);
}

static int	get_nsew_fallback(t_game *game, t_raycast_result *r,
								float o_x, float o_y)
{
	if (utls_fabs_sub(r->x_detect, o_x) > utls_fabs_sub(r->y_detect, o_y))
	{
		if (game->player->coords->y < r->y_detect)
			return (2);
		else
			return (1);
	}
	else
	{
		if (game->player->coords->x < r->x_detect)
			return (4);
		else
			return (3);
	}
	return (1);
}

void	utls_ray_differ(t_game *game, t_raycast_result *r, float o_x, float o_y)
{
	float	diff_x;
	float	diff_y;
	int		nsew;

	nsew = get_nsew(r->x_detect, r->y_detect);
	if (nsew <= 0)
		nsew = get_nsew(o_x, o_y);
	if (nsew <= 0)
		nsew = get_nsew_fallback(game, r, o_x, o_y);
	diff_x = r->x_detect - (int)r->x_detect;
	diff_y = r->y_detect - (int)r->y_detect;
	r->nsew = nsew;
	if (nsew == 1)
		r->x_texture_position = (int)(64 * (1 - diff_x)) % 64;
	if (nsew == 2)
		r->x_texture_position = (int)(64 * diff_x) % 64;
	if (nsew == 3)
		r->x_texture_position = (int)(64 * (1 - diff_y)) % 64;
	if (nsew == 4)
		r->x_texture_position = (int)(64 * diff_y) % 64;
}

void	utls_ray_result(t_game *game, t_raycast_result *r)
{
	static float	old_x = -1.0;
	static float	old_y = -1.0;

	if (r->ray_number + 1 < RAY_COUNT)
	{
		if (old_x == -1)
		{
			old_x = r->x_detect;
			old_y = r->y_detect;
			return ;
		}
		utls_ray_differ(game, r, old_x, old_y);
		old_x = r->x_detect;
		old_y = r->y_detect;
		return ;
	}
	old_x = -1.0;
}
