/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:58:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 00:34:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ps_info_init(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
}

int		main(int ac, char *av[])
{
	t_link	*a;
	t_link	*b;
	t_info	info;

	if (ac < 2)
		exit (-1);
	a = 0;
	b = 0;
	ps_info_init(&info);
	a = ps_start(av, &info);
	// op_sa(&a, &info);
	// op_ra(&a, &info);
	// op_ra(&a, &info);
	// op_rra(&a, &info);
	op_pb(&a, &b, &info);
	op_pb(&a, &b, &info);
	op_pb(&a, &b, &info);
	op_pb(&a, &b, &info);
	op_pb(&a, &b, &info);
	op_pb(&a, &b, &info);
	t_link *link;
	link = move_stat(b);
	printf("%ld\t%ld\n", link->val, b->val);
	op_rb(&b, &info);
	// op_rb(&b, &info);
	// op_pa(&a, &b, &info);
	// op_sb(&b, &info);
	// op_rrb(&b, &info);
	// op_rrb(&b, &info);
	// op_ss(&a, &b, &info);
	printf("============\n");
	while (a)
	{
		printf("%ld\n", a->val);
		a = a->prev;
	}
	printf("============\n");
	// op_sa(&b, &info);
	// op_ra(&b, &info);
	while (b)
	{
		printf("%ld\n", b->val);
		b = b->prev;
	}
	printf("============\n");
}
