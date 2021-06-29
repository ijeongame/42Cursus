/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:51:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 22:16:17 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_check_small(t_link *link, long pivot)
{
	while (link)
	{
		if (link->val > pivot)
			return (0);
		link = link->next;
	}
	return (1);
}

void	algo_init_flag_b(t_link **b, t_info *info, t_flag *flag, int cnt)
{
	algo_pivot(*b, info, cnt);
	flag->cnt_ra = 0;
	flag->cnt_rb = 0;
	flag->cnt_pa = 0;
	flag->cnt_pb = 0;
}

void	algo_b_reverse(t_info *info, t_flag *flag, int *cnt)
{
	exec_op(&info->a, &info->b, info, RB);
	flag->cnt_rb++;
	(*cnt)--;
}

void	algo_b_push(t_info *info, t_flag *flag, int *cnt)
{
	exec_op(&info->a, &info->b, info, PA);
	flag->cnt_pa++;
	(*cnt)--;
}

void	algo_b_to_a(t_info *info, int cnt)
{
	t_flag	flag;

	if (escape_b(&info->a, &info->b, info, cnt))
		return ;
	algo_init_flag_b(&info->b, info, &flag, cnt);
	while (cnt > 0)
	{
		if (info->b->val > info->pivot[1])
		{
			algo_b_push(info, &flag, &cnt);
			algo_rotation_b(info, &flag, &cnt);
		}
		else
		{
			if (algo_check_small(info->a, info->pivot[1]))
				break ;
			algo_b_reverse(info, &flag, &cnt);
		}
	}
	algo_a_to_b(info, flag.cnt_pa - flag.cnt_ra);
	algo_reset_rotate(&info->a, &info->b, info, flag);
	algo_a_to_b(info, flag.cnt_ra);
	algo_b_to_a(info, flag.cnt_rb + cnt);
}
