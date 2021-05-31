/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:58:15 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/31 23:25:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	re_rotate(t_link **a, t_link **b, t_info *info)
// {
// 	if (info->rb_cnt > info->ra_cnt)
// 	{
// 		while (info->rb_cnt-- != info->ra_cnt)
// 			exec_op(a, b, info, RRB);
// 		while (info->ra_cnt--)
// 			exec_op(a, b, info, RRR);
// 	}
// 	else
// 	{
// 		while (info->ra_cnt-- != info->rb_cnt)
// 			exec_op(a, b, info, RRA);
// 		while (info->rb_cnt--)
// 			exec_op(a, b, info, RRR);
// 	}
// }

int		sort_check_b(t_link *link)
{
	while (link->next)
	{
		if (link->val < link->next->val)
			return (0);
		link = link->next;
	}
	return (1);
}

int		sort_check_a(t_link *link)
{
	while (link->next)
	{
		if (link->val > link->next->val)
			return (0);
		link = link->next;
	}
	return (1);
}
