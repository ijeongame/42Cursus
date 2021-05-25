/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 23:40:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_lst **a, t_info *info)
{
	t_lst	*node;
	long	tmp;

	if (info->a_size < 2)
		return ;
	node = move_stat(*a);
	tmp = node->val;
	node->next->prev = 0;
	free(node);
	(*a)->next = new_lst_tail(*a, tmp);
	(*a) = (*a)->next;
}
