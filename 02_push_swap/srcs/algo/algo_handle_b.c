/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_handle_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:59:07 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 04:11:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		type1(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RB);
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RRB);
	exec_op(a, b, info, SB);
}

static void		type2(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RB);
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RRB);
}

static void		type3(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, RB);
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RRB);
	exec_op(a, b, info, SB);
}

static void		type4(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, RB);
	exec_op(a, b, info, SB);
	exec_op(a, b, info, RRB);
}

void			algo_handle_b(t_link **a, t_link **b, t_info *info)
{
	if ((*b)->val < (*b)->next->val && \
	(*b)->next->val < (*b)->next->next->val)
		type1(a, b, info);
	else if ((*b)->val < (*b)->next->next->val && \
	(*b)->next->next->val < (*b)->next->val)
		type2(a, b, info);
	else if ((*b)->next->val < (*b)->val && \
	(*b)->val < (*b)->next->next->val)
		type3(a, b, info);
	else if ((*b)->next->next->val < (*b)->val && \
	(*b)->val < (*b)->next->val)
		swap_b(a, b, info);
	else if ((*b)->next->val < (*b)->next->next->val && \
	(*b)->next->next->val < (*b)->val)
		type4(a, b, info);
}
