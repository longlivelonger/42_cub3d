/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:37 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:16 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lenght_src;
	size_t	lenght_dst;
	size_t	count_to_add;
	size_t	i;

	lenght_dst = 0;
	while (*(dst + lenght_dst) != '\0')
		lenght_dst++;
	lenght_src = 0;
	while (*(src + lenght_src) != '\0')
		lenght_src++;
	if (dstsize >= lenght_dst + 1)
	{
		count_to_add = dstsize - lenght_dst - 1;
		i = 0;
		while (*(src + i) != '\0' && i < count_to_add)
		{
			*(dst + lenght_dst + i) = *(src + i);
			i++;
		}
		*(dst + lenght_dst + i) = '\0';
		return (lenght_dst + lenght_src);
	}
	else
		return (lenght_src + dstsize);
}
