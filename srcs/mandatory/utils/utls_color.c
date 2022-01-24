/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:46:49 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	utls_color_to_int(t_color c)
{
	int	result;

	result = 0;
	result = (result << 8) + c.red;
	result = (result << 8) + c.green;
	result = (result << 8) + c.blue;
	return (result);
}
