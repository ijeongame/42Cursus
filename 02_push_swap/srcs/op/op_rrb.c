/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:33:40 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:10:17 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb(t_link **b, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->b_size < 2)
		return ;
	link = move_stat(*b);
	tmp = link->val;
	link->next->prev = 0;
	free(link);
	(*b)->next = new_lst_tail(*b, tmp);
	(*b) = (*b)->next;
}
