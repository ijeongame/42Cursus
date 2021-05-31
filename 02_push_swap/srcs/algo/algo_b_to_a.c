/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:51:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 05:04:55 by hkwon            ###   ########.fr       */
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

void	algo_init_flag_b(t_link **b, t_info *info, int flag[7], int cnt)
{
	algo_pivot(*b, info, cnt);
	ft_memset(flag, 0, sizeof(int) * 6);
	if (cnt == info->b_size)
		flag[F_FL] = 1;
	flag[F_RB] = 0;
	flag[F_PA] = 0;
}

void	algo_rotate_b(t_link **a, t_link **b, t_info *info, int flag[7])
{
	flag[F_I] = flag[F_RB];
	while (flag[F_I] && !flag[F_FL])
	{
		exec_op(a, b, info, RRB);
		flag[F_I]--;
	}
}

void	algo_b_to_a(t_link **a, t_link **b, t_info *info, int cnt)
{
	int		flag[7];

	if (escape_b(a, b, info, cnt))
		return ;
	algo_init_flag_b(b, info, flag, cnt);
	while (cnt > 0)
	{
		if ((*b)->val > info->pivot)
		{
			exec_op(a, b, info, PA);
			flag[F_PA]++;
		}
		else
		{
			if (algo_check_small(*b, info->pivot))
				break ;
			exec_op(a, b, info, RB);
			flag[F_RB]++;
		}
		cnt--;
	}
	algo_rotate_b(a, b, info, flag);
	algo_a_to_b(a, b, info, flag[F_PA]);
	algo_b_to_a(a, b, info, flag[F_RB] + cnt);
}
