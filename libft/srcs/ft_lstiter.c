/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:22:44 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:00 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*backup;

	if (NULL == lst || NULL == f)
		return ;
	while (NULL != lst)
	{
		backup = lst->next;
		f(lst->content);
		lst = backup;
	}
}
