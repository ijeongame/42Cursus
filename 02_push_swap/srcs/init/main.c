/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:58:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 20:46:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_info_init(t_info *info)
{
	info->max = 0;
	info->min = 0;
	info->pivot[0] = 0;
	info->pivot[1] = 0;
	info->pos = 0;
	info->a_size = 0;
	info->b_size = 0;
}

int		main(int ac, char *av[])
{
	t_info	info;

	if (ac < 2)
		exit(1);
	info.a = 0;
	info.b = 0;
	ps_info_init(&info);
	info.a = ps_start(av, &info);
	info.a = move_link_head(info.a);
	algo_init(&info);
	free_link(&info.a);
	return (0);
}
