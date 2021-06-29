/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 03:58:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 22:06:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		escape_a(t_link **a, t_link **b, t_info *info, int cnt)
{
	if (cnt == 1)
		;
	else if (cnt == 2)
	{
		if ((*a)->val > (*a)->next->val)
			exec_op(a, b, info, SA);
	}
	else if (cnt == 3)
		algo_handle_a(a, b, info);
	else if (sort_check_a(*a, cnt))
		;
	else
		return (0);
	return (1);
}

int		escape_b(t_link **a, t_link **b, t_info *info, int cnt)
{
	if (cnt == 1)
		exec_op(a, b, info, PA);
	else if (cnt == 2)
	{
		if ((*b)->val < (*b)->next->val)
			exec_op(a, b, info, SB);
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else if (cnt == 3)
	{
		algo_handle_b(a, b, info);
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else if (sort_check_b(*b, cnt))
	{
		while (cnt--)
			exec_op(a, b, info, PA);
	}
	else
		return (0);
	return (1);
}

void	algo_rotation_a(t_info *info, t_flag *flag, int *cnt)
{
	if (info->b->val > info->pivot[1])
	{
		if ((*cnt) > 0 && info->a->val > info->pivot[0])
		{
			exec_op(&info->a, &info->b, info, RR);
			flag->cnt_ra++;
			(*cnt)--;
		}
		else
			exec_op(&info->a, &info->b, info, RB);
		flag->cnt_rb++;
	}
}

void	algo_rotation_b(t_info *info, t_flag *flag, int *cnt)
{
	if (info->a->val < info->pivot[0])
	{
		if ((*cnt) > 0 && info->b->val <= info->pivot[1])
		{
			exec_op(&info->a, &info->b, info, RR);
			(*cnt)--;
			flag->cnt_rb++;
		}
		else
			exec_op(&info->a, &info->b, info, RA);
		flag->cnt_ra++;
	}
}

void	algo_reset_rotate(t_link **a, t_link **b, t_info *info, t_flag flag)
{
	if (flag.cnt_rb > flag.cnt_ra)
	{
		while (flag.cnt_rb-- != flag.cnt_ra)
			exec_op(a, b, info, RRB);
		while (flag.cnt_ra--)
			exec_op(a, b, info, RRR);
	}
	else
	{
		while (flag.cnt_ra-- != flag.cnt_rb)
			exec_op(a, b, info, RRA);
		while (flag.cnt_rb--)
			exec_op(a, b, info, RRR);
	}
}
