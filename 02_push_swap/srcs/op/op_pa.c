/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/28 18:16:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_link **a, t_link **b, t_info *info)
{
	if (!info->b_size)
		return ;
	if (!(*a))
		*a = new_link_head(0, (*b)->val);
	else
	{
		(*a)->prev = new_link_head(*a, (*b)->val);
		(*a) = (*a)->prev;
	}
	delete_link(b);
	info->a_size++;
	info->b_size--;
	write(1, "pa\n", 3);
}
