/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:40:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/05 20:05:15 by hkwon            ###   ########.fr       */
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
}

static int	check_philo(t_info *info, int ac)
{
	if (info->num_of_philo < 0)
		return (1);
	if (info->time_to_die < 0)
		return (1);
	if (info->time_to_eat < 0)
		return (1);
	if (info->time_to_sleep < 0)
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
	if (!info->philo)
		return (1);
	if (!info->fork)
		return (1);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philo[i].n = i;
		pthread_mutex_init(&info->fork[i], NULL);
		if (i == 0)
			info->philo[i].fork_l = &info->fork[info->num_of_philo - 1];
		else
			info->philo[i].fork_l = &info->fork[i - 1];
		info->philo[i].fork_r = &info->fork[i];
		info->philo[i].info = info;
		++i;
	}
	return (0);
}

int			start_philo(t_info *info, int ac, char *av[])
{
	set_philo(info, ac, av);
	if (check_philo(info, ac))
		return (1);
	if (init_philo(info))
		return (1);
	return (0);
}
