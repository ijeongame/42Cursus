/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:50:59 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 22:07:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_check_big(t_link *link, long pivot)
{
	while (link)
	{
		if (link->val <= pivot)
			return (0);
		link = link->next;
	}
	return (1);
}

void	algo_init_flag_a(t_link **a, t_info *info, t_flag *flag, int cnt)
{
	algo_pivot(*a, info, cnt);
	flag->cnt_ra = 0;
	flag->cnt_rb = 0;
	flag->cnt_pa = 0;
	flag->cnt_pb = 0;
}

void	algo_a_reverse(t_info *info, t_flag *flag, int *cnt)
{
	exec_op(&info->a, &info->b, info, RA);
	flag->cnt_ra++;
	(*cnt)--;
}

void	algo_a_push(t_info *info, t_flag *flag, int *cnt)
{
	exec_op(&info->a, &info->b, info, PB);
	flag->cnt_pb++;
	(*cnt)--;
}

void	algo_a_to_b(t_info *info, int cnt)
{
	t_flag		flag;

	if (escape_a(&info->a, &info->b, info, cnt))
		return ;
	algo_init_flag_a(&info->a, info, &flag, cnt);
	while (cnt > 0)
	{
		if (info->a->val > info->pivot[0])
		{
			if (algo_check_big(info->a, info->pivot[0]))
				break ;
			algo_a_reverse(info, &flag, &cnt);
		}
		else
		{
			algo_a_push(info, &flag, &cnt);
			algo_rotation_a(info, &flag, &cnt);
		}
	}
	algo_reset_rotate(&info->a, &info->b, info, flag);
	algo_a_to_b(info, flag.cnt_ra + cnt);
	algo_b_to_a(info, flag.cnt_rb);
	algo_b_to_a(info, flag.cnt_pb - flag.cnt_rb);
}
