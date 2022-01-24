/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:37:54 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	z_array_init(t_z_array *a)
{
	(*a).size = 0;
	(*a).elem = NULL;
	(*a).elem = utls_malloc(sizeof(char **), 1);
	if (NULL == (*a).elem)
	{
		(*a).status = 1;
		return (1);
	}
	(*a).status = 0;
	return (0);
}

int	z_array_append(t_z_array *a, char *str)
{
	char		**temp;
	char		*tstr;
	int			i;

	if ((*a).status != 0)
		return (1);
	i = 0;
	tstr = ft_strdup(str);
	if (NULL == tstr)
		return (1);
	temp = utls_malloc(sizeof(char *), (*a).size + 1);
	if (NULL == temp)
	{
		free(tstr);
		return (1);
	}
	*(temp + (*a).size) = tstr;
	i = (*a).size;
	while (i-- != 0)
		temp[i] = (*a).elem[i];
	free((*a).elem);
	(*a).elem = temp;
	(*a).size += 1;
	return (0);
}

int	z_array_remove(t_z_array *a, size_t index)
{
	size_t	i;
	char	*backup;

	if ((*a).status != 0)
		return (1);
	if (index + 1 > (*a).size || (*a).size == 0)
		return (1);
	backup = (*a).elem[index];
	if (index + 1 != (*a).size)
	{
		i = index;
		while (i < (*a).size - 1)
		{
			(*a).elem[i] = (*a).elem[i + 1];
			i++;
		}
	}
	(*a).size -= 1;
	free(backup);
	(*a).elem[(*a).size] = NULL;
	return (0);
}

int	z_array_free(t_z_array *a)
{
	int	i;

	i = a->size;
	while (--i >= 0)
	{
		free((*a).elem[i]);
		(*a).elem[i] = NULL;
	}
	free((*a).elem);
	(*a).elem = NULL;
	return (0);
}
