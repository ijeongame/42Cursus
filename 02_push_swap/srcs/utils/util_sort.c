/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:58:15 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 04:08:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_link **a, t_link **b, t_info *info)
{
	if ((*b) && (*b)->next)
	{
		if ((*b)->val < (*b)->next->val)
			exec_op(a, b, info, SS);
		else
			exec_op(a, b, info, SA);
	}
	else
		exec_op(a, b, info, SA);
}

void	swap_b(t_link **a, t_link **b, t_info *info)
{
	if ((*a) && (*a)->next)
	{
		if ((*a)->val > (*a)->next->val)
			exec_op(a, b, info, SS);
		else
			exec_op(a, b, info, SB);
	}
	else
		exec_op(a, b, info, SB);
}

int		sort_check_b(t_link *link)
{
	while (link->next)
	{
		if (link->val < link->next->val)
			return (0);
		link = link->next;
	}
	return (1);
}

int		sort_check_a(t_link *link)
{
	while (link->next)
	{
		if (link->val > link->next->val)
			return (0);
		link = link->next;
	}
	return (1);
}
