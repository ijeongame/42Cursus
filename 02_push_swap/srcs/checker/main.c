/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:20:28 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 06:27:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_info_init(t_info *info)
{
	info->max = 0;
	info->min = 0;
	info->pivot = 0;
	info->pos = 0;
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
	check_init(&a, &b, &info);
	free_link(&a);
	return (0);
}
