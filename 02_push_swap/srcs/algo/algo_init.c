/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:13:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/29 22:09:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_link **a, t_link **b, t_info *info)
{
	int		i;

	if (info->a_size == 1 || sort_check(*a))
		return ;

	algo_pivot(*a, info);
	i = info->a_size;
	while (!sort_check(*a) && i > 0)
	{
		if ((*a)->val == info->max)
			op_ra(a, info);
		if ((*a)->val > (*a)->next->val)
			op_sa(a, info);
		// if ((*a)->val <= info->pivot)
		// 	op_pb(a, b, info);
		// else
		// 	op_ra(a, info);
		i--;
	}
	// while (info->b_size)
	// {
	// 	algo_pivot(*b, info);
	// 	if ((*b)->val == info->max)
	// 		op_pa(a, b, info);
	// 	else
	// 		op_rb(b, info);
	// }
	algo_init(a, b, info);
}
