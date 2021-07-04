/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/04 19:39:12 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_info *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		info->num_must_eat = -1;
	else
		info->num_must_eat = ft_atoi(av[5]);
}

int			main(int ac, char *av[])
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (0);
	memset(&info, 0, sizeof(info));
	init_philo(&info, ac, av);
	print(info);
}
