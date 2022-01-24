/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:42:08 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*utls_malloc(int size, int count)
{
	void	*result;

	result = malloc(size * count);
	if (NULL == result)
	{
		errors_print_ln(ERRORS_MALLOC);
		exit(1);
	}
	return ((void *)result);
}

void	utls_free(void *p)
{
	if (NULL != p)
		free(p);
	p = NULL;
}

float	utls_fabs_sub(float a, float b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}
