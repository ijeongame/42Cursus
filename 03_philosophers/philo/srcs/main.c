/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/07 23:03:03 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_and_free_philo(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		pthread_mutex_destroy(&info->philo[i++].eat_mutex);
	}
	free(info->philo);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork[i++]);
	free(info->fork);
}

static void	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = 0;
	gettimeofday(&info->start_time, NULL);
	while (i < info->num_of_philo)
	{
		info->philo[i].last_eat_time = info->start_time;
		pthread_create(&info->philo[i].thread, NULL, philo, &info->philo[i]);
		pthread_create(&thread, NULL, monitor, &info->philo[i]);
		pthread_detach(thread);
		++i;
	}
	if (info->num_must_eat)
	{
		pthread_create(&thread, NULL, monitor_must_eat, info);
		pthread_detach(thread);
	}
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (0);
	memset(&info, 0, sizeof(info));
	if (init(&info, ac, av))
		return (0);
	init_thread(&info);
	join_and_free_philo(&info);
}
