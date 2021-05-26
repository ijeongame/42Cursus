/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:31:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 23:52:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_link **a, t_link **b, t_info *info)
{
	if (!info->a_size)
		return ;
	if (!(*b))
		*b = new_link_tail(0, (*a)->val);
	else
	{
		(*b)->next = new_link_tail(*b, (*a)->val);
		(*b) = (*b)->next;
	}
	delete_link(a);
	info->a_size--;
	info->b_size++;
}
