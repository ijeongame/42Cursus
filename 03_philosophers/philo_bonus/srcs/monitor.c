/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:11:40 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/29 23:45:30 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_died(void *arg)
{
	t_philo	*philo;
	
	philo = arg;
	sem_wait(philo->info->died);
	if (philo->philo_died)
	{
		sem_post(philo->info->died);
		sem_post(philo->info->fork);
		sem_post(philo->info->fork);
		exit(1);
	}
	philo->info->finish = DIED;
	sem_post(philo->info->died);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	exit(0);
}

void	*monitor_full(void *arg)
{
	t_info	*info;
	int		cnt;

	info = arg;
	cnt = 0;
	while (1)
	{
		sem_wait(info->full);
		if (info->finish)
			break ;
		cnt++;
		if (cnt == info->num_of_philo)
			break;
	}
	print_msg(info->philo, FULL);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->eating);
		if (get_time() - philo->last_eat_time >= philo->info->time_to_die)
		{
			print_msg(philo, DIED);
			philo->info->finish = DIED;
			philo->philo_died = 1;
			sem_post(philo->info->died);
			sem_post(philo->eating);
			return (NULL);
		}
		sem_post(philo->eating);
		usleep(100);
	}
	return (NULL);
}