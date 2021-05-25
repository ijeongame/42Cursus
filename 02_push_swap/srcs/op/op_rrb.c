/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:33:40 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 23:50:30 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb(t_lst **b, t_info *info)
{
	t_lst	*node;
	long	tmp;

	if (info->b_size < 2)
		return ;
	node = move_stat(*b);
	tmp = node->val;
	node->next->prev = 0;
	free(node);
	(*b)->next = new_lst_tail(*b, tmp);
	(*b) = (*b)->next;
}
