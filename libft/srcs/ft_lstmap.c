/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:29:06 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:07 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iterator;
	t_list	*result;
	t_list	*tmp;

	if (NULL == lst)
		return (NULL);
	result = NULL;
	result = ft_lstnew(f(lst->content));
	if (NULL == result)
		return (NULL);
	iterator = result;
	lst = lst->next;
	while (NULL != lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (NULL == tmp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&iterator, tmp);
		iterator = iterator->next;
		lst = lst->next;
	}
	return (result);
}
