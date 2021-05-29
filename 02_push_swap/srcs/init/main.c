/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:58:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/29 22:09:38 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_info_init(t_info *info)
{
	info->max = 0;
	info->min = 0;
	info->pivot = 0;
	info->a_size = 0;
	info->b_size = 0;
}

int		main(int ac, char *av[])
{
	t_link	*a;
	t_link	*b;
	t_info	info;

	if (ac < 2)
		exit(1);
	a = 0;
	b = 0;
	ps_info_init(&info);
	a = ps_start(av, &info);
	a = move_link_head(a);
	algo_init(&a, &b, &info);

	printf("==========\n");
	printf("main\n");
	printf("==========\n");
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

	free_link(&a);


}
