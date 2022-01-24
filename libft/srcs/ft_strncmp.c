/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:27 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:33 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	ch1;
	unsigned char	ch2;

	index = 0;
	while (*(s1 + index) != '\0' && *(s2 + index) != '\0' && index < n)
	{
		ch1 = *(s1 + index);
		ch2 = *(s2 + index);
		if (ch1 != ch2)
		{			
			return (ch1 - ch2);
		}
		index++;
	}
	if (index == n)
		return (0);
	if (*(s1 + index) == *(s2 + index))
		return (0);
	else
	{
		ch1 = *(s1 + index);
		ch2 = *(s2 + index);
		return (ch1 - ch2);
	}
}
