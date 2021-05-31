/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:51:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 02:26:36 by hkwon            ###   ########.fr       */
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

void	print_b_num(t_link *a, t_link *b, t_info *info, int rb, int pa, int cnt)
{
	printf("min : %ld\n", info->min);
	printf("max : %ld\n", info->max);
	printf("pivot : %ld\n", info->pivot);
	printf("rb_cnt : %d\n", rb);
	printf("pa_cnt : %d\n", pa);
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

void	algo_b_to_a(t_link **a, t_link **b, t_info *info, int cnt)
{
	printf("============\n");
	printf("min : %ld\n", info->min);
	printf("max : %ld\n", info->max);
	printf("pivot : %ld\n", info->pivot);
	printf("cnt : %d\n", cnt);
	if (escape_b(a, b, info, cnt))
		return ;
	int rb = 0;
	int pa = 0;
	printf("======b_to_a_start======\n");
	algo_pivot(*b, info, cnt);
	print_b_num(*a, *b, info, rb, pa, cnt);
	while (cnt > 0)
	{
		print_b_num(*a, *b, info, rb, pa, cnt);
		if ((*b)->val > info->pivot)
		{
			exec_op(a, b, info, PA);
			pa++;
		}
		else
		{
			if (algo_check_small(*b, info->pivot))
				break ;
			exec_op(a, b, info, RB);
			rb++;
		}
		cnt--;
	}
	int i = rb;
	while (i)
	{
		exec_op(a, b, info, RRB);
		i--;
	}
	algo_a_to_b(a, b, info, pa);
	algo_b_to_a(a, b, info, rb + cnt);
}
