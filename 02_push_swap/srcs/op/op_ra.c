/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:09 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/25 21:42:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_lst **a, t_info *info)
{
	t_lst	*n_head;
	long	tmp;

	if (info->a_size < 0)
		return ;
	tmp = (*a)->val;
	n_head = move_head(*a);
	n_head->prev = new_node_head(n_head, tmp);
	delete_lst(a);
}
