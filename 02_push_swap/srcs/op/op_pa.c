/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 00:42:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_lst **a, t_lst **b, t_info *info)
{
	if (!info->b_size)
		return ;
	if (!(*a))
		*a = new_lst_tail(0, (*b)->val);
	else
	{
		(*a)->next = new_lst_tail(*a, (*b)->val);
		(*a) = (*a)->next;
		delete_lst(**b);
	}
	info->a_size++;
	info->b_size--;
}
