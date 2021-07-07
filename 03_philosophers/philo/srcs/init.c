/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:40:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/07 21:35:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo(t_info *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_must_eat = ft_atoi(av[5]);
	pthread_mutex_init(&info->fin_mutex, NULL);
}

static int	check_philo(t_info *info, int ac)
{
	if (info->num_of_philo < 0 || info->num_of_philo > 200)
		return (1);
	if (info->time_to_die < 60)
		return (1);
	if (info->time_to_eat < 60)
		return (1);
	if (info->time_to_sleep < 60)
		return (1);
	if (ac == 6 && info->num_must_eat < 0)
		return (1);
	return (0);
}

static int	init_philo(t_info *info)
{
	int	i;

	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	info->fork = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->philo || !info->fork)
		return (1);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philo[i].n = i;
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
		if (pthread_mutex_init(&info->philo[i].eat_mutex, NULL))
			return (1);
		info->philo[i].fork_l = &info->fork[i];
		info->philo[i].fork_r = &info->fork[(i + 1) % info->num_of_philo - 1];
		info->philo[i].info = info;
		++i;
	}
	return (0);
}

int	init(t_info *info, int ac, char *av[])
{
	set_philo(info, ac, av);
	if (check_philo(info, ac))
		return (1);
	if (init_philo(info))
		return (1);
	return (0);
}
