/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:11:40 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/25 20:48:46 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_full(void *av)
{
	t_info *info;
	int		cnt;

	info = av;
	cnt = 0;
	while (1)
	{
		sem_wait(info->full);
		if (info->finish)
			return (NULL);
		cnt++;
		if (cnt == info->num_of_philo)
			break;
	}
	print_full(FULL);
	return (NULL);
}

void	*monitor(void *av)
{
	t_philo *philo;

	philo = av;
	while (1)
	{
		sem_wait(philo->eating);
		if (get_time() - philo->last_eat_time >= philo->info->time_to_die)
		{
			philo->info->finish = DIED;
			philo->philo_died = 1;
			sem_post(philo->info->died);
			sem_post(philo->eating);
		}
		sem_post(philo->eating);
		usleep(100);
	}
	return (NULL);
}

void	*routine(void *av)
{
	t_philo			*philo;

	philo = av;
	if (philo->n % 2 == 0)
		usleep(1000 * philo->info->time_to_eat);
	while (!philo->info->finish)
	{
		eating(philo);
		if (philo->info->num_must_eat > 0 && check_full(philo))
			break ;
		sleeping(philo);;
		thinking(philo);
	}
	return (NULL);
}