/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:11:40 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/31 18:29:12 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_died(void *arg)
{
	t_info	*info;
	int		i;

	i = -1;
	info = arg;
	sem_wait(info->died);
	while (++i < info->num_of_philo)
		kill(info->philo[i].pid, SIGTERM);
	return (NULL);
}

void	*monitor_full(void *arg)
{
	t_info	*info;
	int		full;

	info = arg;
	full = -1;
	while (++full < info->num_of_philo)
		sem_wait(info->full);
	if (info->finish == DIED)
		return (NULL);
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
			sem_wait(philo->info->text);
			print_died(philo);
			philo->info->finish = DIED;
			philo->philo_died = 1;
			sem_post(philo->info->died);
			return (NULL);
		}
		sem_post(philo->eating);
		usleep(100);
	}
	return (NULL);
}
