/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:21:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/08 19:19:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_must_eat(void *av)
{
	t_info	*info;

	info = av;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->fin_mutex);
		if (info->must_eat_cnt == info->num_of_philo)
			info->finish = 1;
		pthread_mutex_unlock(&info->fin_mutex);
	}
	return (NULL);
}

void	*monitor(void *av)
{
	t_philo			*philo;
	struct timeval	time;
	long long		ms;

	philo = av;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		pthread_mutex_lock(&philo->info->fin_mutex);
		gettimeofday(&time, NULL);
		ms = get_time(time) - get_time(philo->last_eat_time);
		gettimeofday(&time, NULL);
		if (ms >= philo->info->time_to_die)
		{
			printf("%lld\t%d\t %s\n", get_time(time) - \
			get_time(philo->info->start_time), philo->n + 1, "died");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		pthread_mutex_unlock(&philo->info->fin_mutex);
	}
	return (NULL);
}
