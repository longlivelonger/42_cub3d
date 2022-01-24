/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_map_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:27:26 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/17 16:05:28 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_tests_is_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b'
		|| filename[len - 2] != 'u'
		|| filename[len - 3] != 'c'
		|| filename[len - 4] != '.')
		return (-1);
	return (0);
}

int	map_tests_is_valid_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}
