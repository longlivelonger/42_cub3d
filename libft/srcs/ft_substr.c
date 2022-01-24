/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:59:54 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:49 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	indexes;
	size_t	whatslengh;

	if (NULL == s)
		return (NULL);
	indexes = ft_strlen(s) - 1;
	if (indexes < start || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (indexes - start + 1 > len)
		whatslengh = len;
	else
		whatslengh = indexes - start + 1;
	result = NULL;
	result = malloc(sizeof(*result) * whatslengh + 1);
	if (NULL == result)
		return (result);
	indexes = 0;
	while (whatslengh--)
	{
		*(result + indexes) = *(s + start + indexes);
		indexes++;
	}
	*(result + indexes) = '\0';
	return (result);
}
