/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:33:28 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 15:58:48 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || \
		c == '\n' || \
		c == '\v' || \
		c == '\f' || \
		c == '\r' || \
		c == ' '
	)
		return (1);
	return (0);
}

static int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	long long		result;

	i = 0;
	while (ft_isspace(*(str + i)) > 0)
		i++;
	sign = 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = get_sign(*(str + i++));
	if (*(str + i) < '0' || *(str + i) > '9')
		return (0);
	result = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result = result * 10 + (*(str + i++) - '0');
		if (result < 0 && sign > 0)
			return (-1);
		if (result < 0 && sign < 0)
			return (0);
	}	
	result *= sign;
	return ((int)result);
}
