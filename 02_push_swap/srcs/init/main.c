/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:58:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 21:46:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ps_info_init(&info);
	a = ps_start(av, &info);
}
