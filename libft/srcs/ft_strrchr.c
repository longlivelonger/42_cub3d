/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:16 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:41 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	tmp;
	size_t			i;
	size_t			lastposition;
	int				found;

	tmp = (unsigned char) c;
	i = 0;
	lastposition = 0;
	found = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == tmp)
		{
			lastposition = i;
			found++;
		}
		i++;
	}
	if (*(s + i) == '\0' && tmp == 0)
		return ((char *)(s + i));
	if (found > 0)
		return ((char *)(s + lastposition));
	return (0);
}
