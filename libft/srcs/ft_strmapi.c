/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 07:09:12 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:28 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			sizeofs;
	char			*result;

	if (NULL == s || NULL == f)
		return (NULL);
	sizeofs = 0;
	while (*(s + sizeofs++))
		;
	result = NULL;
	result = malloc(sizeof(*result) * sizeofs);
	if (NULL == result)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(result + i) = f(i, *(s + i));
		i++;
	}
	*(result + i) = 0;
	return (result);
}
