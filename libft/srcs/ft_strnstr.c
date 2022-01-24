/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:23 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:37 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index_src;
	size_t	index_sub;

	index_src = 0;
	index_sub = 0;
	if (*(needle + 0) == '\0')
		return ((char *)haystack);
	while (*(haystack + index_src) != '\0' && (index_src < len))
	{
		if (*(haystack + index_src) == *(needle + index_sub))
		{
			if (*(needle + index_sub + 1) == '\0')
				return ((char *)(haystack + index_src - index_sub));
			index_sub++;
		}
		else
		{
			index_src = index_src - index_sub;
			index_sub = 0;
		}
		index_src++;
	}
	return (0);
}
