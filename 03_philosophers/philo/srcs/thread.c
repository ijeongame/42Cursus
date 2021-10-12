/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:35:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/05 14:47:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_full(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num_of_philo)
	{
		if (philo->info->philo[i].eat_cnt != philo->info->num_must_eat)
			return (0);
	}
	philo->info->finish = FULL;
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->n % 2 == 0)
		usleep(1000 * philo->info->time_to_eat);
	while (!philo->info->finish)
	{
		eating(philo);
		if (philo->info->num_must_eat > 0 && check_full(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->mutex);
		if (get_time() - philo->last_eat_time >= philo->info->time_to_die)
		{
			print_msg(philo, DIED);
			philo->info->finish = DIED;
			pthread_mutex_unlock(&philo->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(100);
	}
	return (NULL);
}

int	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = -1;
	info->start_time = get_time();
	while (++i < info->num_of_philo)
	{
		info->philo[i].last_eat_time = get_time();
		if (pthread_create(&thread, NULL, routine, &info->philo[i]))
			return (1);
		pthread_detach(thread);
		if (pthread_create(&info->philo[i].thread, \
			NULL, monitor, &info->philo[i]))
			return (1);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(info->philo[i].thread, NULL))
			return (1);
	}
	return (0);
}
