/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:49:40 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 06:25:00 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_run_push(t_link **a, t_link **b, t_info *info, char *line)
{
	if (!ft_strcmp("pa", line))
		op_pa(a, b, info);
	else if (!ft_strcmp("pb", line))
		op_pb(a, b, info);
}

void	check_run_rot_down(t_link **a, t_link **b, t_info *info, char *line)
{
	if (!ft_strcmp("rra", line))
		op_rra(a, info);
	if (!ft_strcmp("rrb", line))
		op_rrb(b, info);
	if (!ft_strcmp("rrr", line))
		op_rrr(a, b, info);
}

void	check_run_rot_up(t_link **a, t_link **b, t_info *info, char *line)
{
	if (!ft_strcmp("ra", line))
		op_ra(a, info);
	if (!ft_strcmp("rb", line))
		op_rb(b, info);
	if (!ft_strcmp("rr", line))
		op_rr(a, b, info);
}

void	check_run_swap(t_link **a, t_link **b, t_info *info, char *line)
{
	if (!ft_strcmp("sa", line))
		op_sa(a, info);
	if (!ft_strcmp("sb", line))
		op_sb(b, info);
	if (!ft_strcmp("ss", line))
		op_ss(a, b, info);
}
