/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:10 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 23:30:50 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_lst **b, t_info *info)
{
	t_lst	*node;
	long	tmp;

	if (info->b_size < 0)
		return ;
	tmp = (*b)->val;
	node = move_stat(*b);
	node->prev = new_lst_head(node, tmp);
	delete_lst(b);
}
