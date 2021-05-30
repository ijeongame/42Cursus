/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:50:59 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 22:27:00 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_a_to_b(t_link **a, t_link **b, t_info *info)
{
	int i;

	if (sort_check(*a))
		return ;
	// while (!info->cnt)
	// {
	// 	*a = (*a)->next;
	// 	info->cnt--;
	// }
	algo_pivot(*a, info);
	i = info->a_size;
	while (i > 0)
	{
		if ((*a)->val > info->pivot)
			exec_op(a, b, info, PB);
		else
		{
			if (info->a_size <= i / 2)
				break ;
			exec_op(a, b, info, RA);
		}
	}
	algo_b_to_a(a, b, info);
	// while (info->cnt)
	// {
	// 	exec_op(a, b, info, RA);
	// 	info->cnt--;
	// }
	// algo_a_to_b(a, b, info);
}
