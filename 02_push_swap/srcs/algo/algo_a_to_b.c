/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:50:59 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 02:26:40 by hkwon            ###   ########.fr       */
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

void	print_num(t_link *a, t_link *b, t_info *info, int ra, int pb, int cnt)
{
	printf("min : %ld\n", info->min);
	printf("max : %ld\n", info->max);
	printf("pivot : %ld\n", info->pivot);
	printf("ra_cnt : %d\n", ra);
	printf("pb_cnt : %d\n", pb);
	printf("cnt : %d\n", cnt);
	printf("============\n");
	while (a)
	{
		printf("%ld\n", a->val);
		a = a->next;
	}
	while (b)
	{
		printf("\t%ld\n", b->val);
		b = b->next;
	}
	printf("-\t-\n");
	printf("a\tb\n");
	printf("============\n");
	// sleep(1);
}

void	algo_a_to_b(t_link **a, t_link **b, t_info *info, int cnt)
{
	if (escape_a(a, b, info, cnt))
		return ;
	int ra = 0;
	int pb = 0;
	printf("======a_to_b_start======\n");
	algo_pivot(*a, info, cnt);
	print_num(*a, *b, info, ra, pb, cnt);
	while (cnt > 0)
	{
		print_num(*a, *b, info, ra, pb, cnt);
		if ((*a)->val > info->pivot)
		{
			if (algo_check_big(*a, info->pivot))
				break ;
			exec_op(a, b, info, RA);
			ra++;
		}
		else
		{
			exec_op(a, b, info, PB);
			pb++;
		}
		cnt--;
	}
	int i = ra;
	while (i)
	{
		exec_op(a, b, info, RRA);
		i--;
	}
	printf("min : %ld\n", info->min);
	printf("max : %ld\n", info->max);
	printf("pivot : %ld\n", info->pivot);
	printf("ra_cnt : %d\n", ra);
	printf("pb_cnt : %d\n", pb);
	printf("cnt : %d\n", cnt);
	printf("============\n");
	printf("======a_to_b_fin======\n");
	algo_a_to_b(a, b, info, ra + cnt);
	algo_b_to_a(a, b, info, pb);
}
