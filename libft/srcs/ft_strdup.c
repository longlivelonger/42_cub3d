/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:32:41 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:04 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*dublicat;

	lenght = 0;
	while (*(s1 + lenght) != '\0')
		lenght++;
	dublicat = (char *)malloc(lenght * sizeof(*dublicat) + 1);
	if (NULL == dublicat)
		return (NULL);
	lenght = 0;
	while (*(s1 + lenght) != '\0')
	{
		*(dublicat + lenght) = *(s1 + lenght);
		lenght++;
	}
	*(dublicat + lenght) = '\0';
	return (dublicat);
}
