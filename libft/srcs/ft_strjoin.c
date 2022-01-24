/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:26:57 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:12 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*result;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	size_s1 = 0;
	while (*(s1 + size_s1++))
		;
	size_s2 = 0;
	while (*(s2 + size_s2++))
		;
	result = NULL;
	result = (char *)malloc(sizeof(char) * (size_s1 + size_s2 - 1));
	if (NULL == result)
		return (result);
	i = 0;
	while (*(s1 + i))
		*(result++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i))
		*(result++) = *(s2 + i++);
	*(result++) = '\0';
	return (result - (size_s1 + size_s2 - 1));
}
