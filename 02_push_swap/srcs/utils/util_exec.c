/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:23:01 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:37:47 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_switch(t_link **a, t_link **b, t_info *info, int op)
{
	if (op == 0)
	{
		write(1, "sa\n", 3);
		op_sa(a, info);
	}
	if (op == 1)
	{
		write(1, "sb\n", 3);
		op_sb(b, info);
	}
	if (op == 2)
	{
		write(1, "ss\n", 3);
		op_ss(a, b, info);
	}
}

void	exec_up_rotate(t_link **a, t_link **b, t_info *info, int op)
{
	if (op == 3)
	{
		write(1, "ra\n", 3);
		op_ra(a, info);
	}
	if (op == 4)
	{
		write(1, "rb\n", 3);
		op_rb(b, info);
	}
	if (op == 5)
	{
		write(1, "rr\n", 3);
		op_rr(a, b, info);
	}
}

void	exec_down_rotate(t_link **a, t_link **b, t_info *info, int op)
{
	if (op == 6)
	{
		write(1, "rra\n", 4);
		op_rra(a, info);
	}
	if (op == 7)
	{
		write(1, "rrb\n", 4);
		op_rrb(b, info);
	}
	if (op == 8)
	{
		write(1, "rrr\n", 4);
		op_rrr(a, b, info);
	}
}

void	exec_push(t_link **a, t_link **b, t_info *info, int op)
{
	if (op == 9)
	{
		write(1, "pa\n", 3);
		op_pa(a, b, info);
	}
	if (op == 10)
	{
		write(1, "pb\n", 3);
		op_pb(a, b, info);
	}
}

void	exec_op(t_link **a, t_link **b, t_info *info, int op)
{
	if (op >= 0 && op <=2)
		exec_switch(a, b, info, op);
	if (op >= 3 && op <= 5)
		exec_up_rotate(a, b, info, op);
	if (op >= 6 && op <= 8)
		exec_down_rotate(a, b, info, op);
	if (op >= 9 && op <= 10)
		exec_push(a, b, info, op);
}
