/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:18:57 by inshin            #+#    #+#             */
/*   Updated: 2020/11/11 22:24:19 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *start;
	t_list *new;
	t_list *curr;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(start = ft_lstnew(f(lst->content))))
		return (NULL);
	curr = start;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		curr->next = new;
		curr = new;
		lst = lst->next;
	}
	return (start);
}
