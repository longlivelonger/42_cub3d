/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _z_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:21:08 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_z_array	*z_array_c(void)
{
	t_z_array	*z_array;

	z_array = utls_malloc(sizeof(t_z_array), 1);
	z_array_init(z_array);
	return (z_array);
}

void	z_array_d(t_z_array *z_array)
{
	z_array_free(z_array);
	utls_free(z_array);
}
