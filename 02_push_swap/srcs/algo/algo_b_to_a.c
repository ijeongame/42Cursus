/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:51:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 22:25:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_b_to_a(t_link **a, t_link **b, t_info *info)
{
	if (sort_check(*b))
		return ;
	while (info->b_size != 0)
	{
		algo_pivot(*b, info);
		if ((*b)->val == info->max)
			exec_op(a, b, info, PA);
		else
			exec_op(a, b, info, RB);
	}
	// algo_a_to_b(a, b, info);
}
