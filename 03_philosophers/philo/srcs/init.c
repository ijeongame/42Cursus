/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:44:12 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/16 16:45:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_arg(t_info *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_must_eat = ft_atoi(av[5]);
	pthread_mutex_init(&info->text, NULL);
}

static int	check_arg(t_info *info, int ac)
{
	if (info->num_of_philo < 0 || info->num_of_philo > 200)
		return (print_error("error : wrong num of philo\n"));
	if (info->time_to_die < 60)
		return (print_error("error : wrong time to die\n"));
	if (info->time_to_eat < 60)
		return (print_error("error : wrong time to eat\n"));
	if (info->time_to_sleep < 60)
		return (print_error("error : wrong time to sleep\n"));
	if (ac == 6 && info->num_must_eat < 0)
		return (print_error("error : worng num\n"));
	return (0);
}

static int	set_philo(t_info *info)
{
	int	i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	info->fork = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->philo || !info->fork)
		return (1);
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].n = i;
		info->philo[i].eat_cnt = 0;
		info->philo[i].fork_l = i;
		info->philo[i].fork_r = (i + 1) % info->num_of_philo;
		info->philo[i].info = info;
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
		if (pthread_mutex_init(&info->philo[i].mutex, NULL))
			return (1);
	}
	return (0);
}

int	init_philo(t_info *info, int ac, char *av[])
{
	get_arg(info, ac, av);
	if (check_arg(info, ac))
		return (1);
	if (set_philo(info))
		return (1);
	return (0);
}
