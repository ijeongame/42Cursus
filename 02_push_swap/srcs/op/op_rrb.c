/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:33:40 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 19:37:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb(t_link **b, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->b_size < 2)
		return ;
	link = move_link_tail(*b);
	tmp = link->val;
	link->prev->next = 0;
	free(link);
	(*b)->prev = new_link_tail(*b, tmp);
	(*b) = (*b)->prev;
	write(1, "rrb\n", 4);
}
