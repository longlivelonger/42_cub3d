/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:12:18 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:14 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*backup;

	size = 0;
	if (lst == NULL)
		return (0);
	backup = lst;
	while (backup)
	{
		size++;
		backup = backup->next;
	}
	return (size);
}
