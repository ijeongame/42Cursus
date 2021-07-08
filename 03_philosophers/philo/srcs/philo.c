/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:44:12 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/08 22:38:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
	print_philo(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->eat_mutex);
	gettimeofday(&philo->last_eat_time, NULL);
	ms = get_time(philo->last_eat_time) - get_time(philo->info->start_time);
	// pthread_mutex_lock(&philo->info->fin_mutex);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, "is eating");
	philo->eat_cnt += 1;
	if (philo->eat_cnt == philo->info->num_must_eat)
		philo->info->must_eat_cnt += 1;
	// pthread_mutex_unlock(&philo->info->fin_mutex);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
	pthread_mutex_unlock(&philo->eat_mutex);
}

static void	sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_philo(philo, "is thinking");
}

void	*philo(void *av)
{
	t_philo	*philo;

	philo = av;
	if (philo->n % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->finish)
	{
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
