/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:17:24 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 19:01:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*move_link_head(t_link *link)
{
	while (link)
	{
		if (link->prev)
			link = link->prev;
		else
			break ;
	}
	return (link);
}

t_link	*move_link_tail(t_link *link)
{
	while (link)
	{
		if (link->next)
			link = link->next;
		else
			break ;
	}
	return (link);
}

t_link	*new_link_head(t_link *link, long value)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link) + 1);
	if (!new)
		return (0);
	new->next = link;
	new->prev = 0;
	new->val = value;
	return (new);
}

t_link	*new_link_tail(t_link *link, long value)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link) + 1);
	if (!new)
		return (0);
	new->next = 0;
	new->prev = link;
	new->val = value;
	return (new);
}

void	delete_link(t_link **link)
{
	t_link	*tmp;

	tmp = 0;
	if ((*link)->next)
	{
		tmp = (*link)->next;
		tmp->prev = 0;
	}
	free(*link);
	*link = tmp;
}
