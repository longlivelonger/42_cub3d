/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:58 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:19 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp_s;
	char	tmp_c;

	i = 0;
	tmp_s = (char *)s;
	tmp_c = (unsigned char)c;
	while (i < n)
	{
		if (*(tmp_s + i) == tmp_c)
			return (tmp_s + i);
		i++;
	}
	return (0);
}
