/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:21:08 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:31 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	if (dst == src)
		return (dst);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (dst < src)
	{
		while (len--)
		{
			*tmp_dst++ = *tmp_src++;
		}
	}
	else
	{
		while (len--)
		{
			*(tmp_dst + len) = *(tmp_src + len);
		}
	}
	return (dst);
}
