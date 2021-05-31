/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_handle_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:58:29 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 04:08:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		type1(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, RA);
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RRA);
}

static void		type2(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, RA);
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RRA);
	exec_op(a, b, info, SA);
}

static void		type3(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RA);
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RRA);
	exec_op(a, b, info, SA);
}

static void		type4(t_link **a, t_link **b, t_info *info)
{
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RA);
	exec_op(a, b, info, SA);
	exec_op(a, b, info, RRA);
}

void			algo_handle_a(t_link **a, t_link **b, t_info *info)
{
	if ((*a)->val < (*a)->next->next->val && \
	(*a)->next->next->val < (*a)->next->val)
		type1(a, b, info);
	else if ((*a)->next->val < (*a)->val && \
	(*a)->val < (*a)->next->next->val)
		swap_a(a, b, info);
	else if ((*a)->next->next->val < (*a)->val && \
	(*a)->val < (*a)->next->val)
		type2(a, b, info);
	else if ((*a)->next->next->val < (*a)->next->val && \
	(*a)->next->val < (*a)->val)
		type3(a, b, info);
	else if ((*a)->next->val < (*a)->next->next->val && \
	(*a)->next->next->val < (*a)->val)
		type4(a, b, info);
}
