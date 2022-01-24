/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:12:55 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 15:59:37 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

typedef struct t_atoi_var
{
	char	temp[256];
	int		i;
	int		sign;
	char	*result;
}t_atoi_var;

static void	ft_itoa_faction(t_atoi_var *v, int n);

char	*ft_itoa(int n)
{
	t_atoi_var	v;
	int			j;

	if (n < 0)
		v.sign = 1;
	else
		v.sign = 0;
	ft_itoa_faction(&v, n);
	v.result = NULL;
	v.result = malloc(sizeof(*v.result) * (v.i + v.sign + 2));
	if (v.result == NULL)
		return (NULL);
	*(v.result + v.i + v.sign + 1) = '\0';
	j = -1;
	if (v.sign)
		*v.result = '-';
	while (v.i >= ++j)
	{
		*(v.result + v.sign + j) = v.temp[v.i - j] + '0';
	}
	return (v.result);
}

static void	ft_itoa_faction(t_atoi_var *v, int n)
{
	v->i = -1;
	if (n < 0)
	{
		n = (n + 1) * (-1);
		v->temp[++v->i] = n % 10;
		n = n / 10;
		if (v->temp[v->i] == 9)
		{
			v->temp[v->i] = 0;
			n += 1;
		}
		else
			v->temp[v->i] += 1;
	}
	else
	{
		v->temp[++v->i] = n % 10;
		n /= 10;
	}
	while (n > 0)
	{
		v->temp[++v->i] = n % 10;
		n /= 10;
	}
}
