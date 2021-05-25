/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:09 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 23:30:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_lst **a, t_info *info)
{
	t_lst	*node;
	long	tmp;

	if (info->a_size < 0)
		return ;
	tmp = (*a)->val;
	node = move_stat(*a);
	node->prev = new_lst_head(node, tmp);
	delete_lst(a);
}
