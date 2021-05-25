/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:07:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 23:10:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*move_stat(t_lst *lst)
{
	while (lst)
	{
		if (lst->prev)
			lst = lst->prev;
		else
			break ;
	}
	return (lst);
}

t_lst	*new_node_head(t_lst *lst, long value)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst) + 1);
	if (!new)
		return (0);
	new->next = lst;
	new->prev = 0;
	new->val = value;
	return (new);
}

t_lst	*new_node_tail(t_lst *lst, long value)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst) + 1);
	if (!new)
		return (0);
	new->next = 0;
	new->prev = lst;
	new->val = value;
	return (new);
}

void	delete_lst(t_lst **lst)
{
	t_lst	*tmp;

	if ((*lst)->prev)
	{
		tmp = (*lst)->prev;
		tmp->next = 0;
	}
	free(*lst);
	*lst = tmp;
}
