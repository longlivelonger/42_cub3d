/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:32:55 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:48 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_putnbr_recursion(int n, int fd, int divider);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_putnbr_recursion(n, fd, 1);
}

static void	ft_putnbr_recursion(int n, int fd, int divider)
{
	if (divider == 0)
		return ;
	if (n / divider < 10)
	{
		ft_putchar_fd(n / divider + '0', fd);
		if (divider / 10 != 0)
			ft_putnbr_recursion(n % divider, fd, divider / 10);
		return ;
	}
	ft_putnbr_recursion(n, fd, divider * 10);
}
