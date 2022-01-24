/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:33:24 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 15:58:59 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*result;

	result = NULL;
	result = malloc(count * size);
	if (NULL == result)
		return (result);
	i = 0;
	while (i < count * size)
	{
		*((char *)result + i) = 0x0;
		i++;
	}
	return (result);
}
