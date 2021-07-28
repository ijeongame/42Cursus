/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:35:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/28 20:58:15 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int		ft_thread_util(pthread_t *thread, void *func, void *arg)
{
	if (pthread_create(thread, NULL, func, arg))
		return (1);
	pthread_detach(*thread);
	return (0);
}

int		routine(void *arg)
{
	pthread_t	thread;
	t_philo		*philo;

	philo = arg;
	philo->last_eat_time = get_time();
	if (ft_thread_util(&thread, monitor, philo))
		return (1);
	if (ft_thread_util(&thread, monitor_died, philo))
		return (1);
	if (philo->n % 2 == 0)
		usleep(1000 * philo->info->time_to_eat);
	while (!philo->info->finish)
	{
		eating(philo);
		if (philo->info->num_must_eat > 0 && \
		philo->eat_cnt == philo->info->num_must_eat)
		{
			sem_post(philo->info->full);
			philo->info->finish = FULL;
		}
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

int		init_sem(t_info *info)
{
	int			i;
	pthread_t	thread;

	if (ft_thread_util(&thread, monitor_full, info))
		return (1);
	i = -1;
	info->start_time = get_time();
	while (++i < info->num_of_philo)
	{
		info->philo[i].last_eat_time = get_time();
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
			routine(&info->philo[i]);
		else if (info->philo[i].pid < 0)
			print_error("error : fork failed\n");
	}
	return (0);
}