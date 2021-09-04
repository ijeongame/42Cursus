/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:26:26 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/13 18:25:03 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *curr;
	t_list *res;

	if (!(res = ft_lstnew(f(lst->content))))
		return (0);
	curr = res;
	lst = lst->next;
	while (lst)
	{
		if (!(curr->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (res);
}
