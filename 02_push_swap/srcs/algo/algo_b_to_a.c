/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:51:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/06 22:26:20 by hkwon            ###   ########.fr       */
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
	ft_memset(flag, 0, sizeof(int) * 7);
	if (cnt == info->b_size)
		flag[F_FL] = 1;
	flag[F_RB] = 0;
	flag[F_PA] = 0;
	flag[F_RA] = 0;
}

void	algo_rotate_b(t_link **a, t_link **b, t_info *info, int flag[7])
{
	// flag[F_I] = flag[F_RB];
	// while (flag[F_I] && !flag[F_FL])
	// {
	// 	exec_op(a, b, info, RRB);
	// 	flag[F_I]--;
	// }
	flag[F_I] = flag[F_RA];
	flag[F_J] = flag[F_RB];
	if (flag[F_J] > flag[F_I])
	{
		while (flag[F_J]-- != flag[F_I])
			exec_op(a, b, info, RRB);
		while (flag[F_I]--)
			exec_op(a, b, info, RRR);

	}
	else
	{
		while (flag[F_I]-- != flag[F_J])
			exec_op(a, b, info, RRA);
		while (flag[F_J]--)
			exec_op(a, b, info, RRR);
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
		if ((*b)->val > info->pivot[1])
		{
			exec_op(a, b, info, PA);
			flag[F_PA]++;
			if (!algo_check_small(*b, info->pivot) && (*a)->val < info->pivot[0])
			{
				if ((*b)->val > info->pivot[1])
				{
					exec_op(a, b, info, RR);
					cnt--;
					flag[F_RB]++;
				}
				else
					exec_op(a, b, info, RA);
				flag[F_RA]++;
			}
		}
		else
		{
			if (algo_check_small(*b, info->pivot[1]))
				break ;
			exec_op(a, b, info, RB);
			flag[F_RB]++;
		}
		cnt--;
	}
	algo_a_to_b(a, b, info, flag[F_PA] - flag[F_RA]);
	algo_rotate_b(a, b, info, flag);
	algo_a_to_b(a, b, info, flag[F_RA]);
	algo_b_to_a(a, b, info, flag[F_RB] + cnt);
}
