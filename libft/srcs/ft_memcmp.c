/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:55 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:23 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	ch1;
	unsigned char	ch2;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		ch1 = *((char *)s1 + index);
		ch2 = *((char *)s2 + index);
		if (ch1 != ch2)
		{
			return (ch1 - ch2);
		}
		index++;
	}
	return (0);
}
