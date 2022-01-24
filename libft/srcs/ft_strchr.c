/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:44 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:00 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	tmp;
	size_t			i;

	tmp = (unsigned char) c;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == tmp)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (*(s + i) == '\0' && tmp == 0)
		return ((char *)(s + i));
	return (0);
}
