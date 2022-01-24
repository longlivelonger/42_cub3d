/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:58:17 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 15:59:53 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*backup;

	if (NULL == lst || NULL == del)
		return ;
	while (NULL != *lst)
	{
		backup = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = backup;
	}
}
