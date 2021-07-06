/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:21:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/06 22:40:49 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(struct timeval	time)
{
	long long	ms;

	ms = time.tv_sec / 1000 + time.tv_usec * 1000;
	return (ms);
}

void	*monitor(void *av)
{
	t_philo			*philo;
	struct timeval	time;
	long long		ms;

	philo = av;
	if (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		pthread_mutex_lock(&philo->info->fin_mutex);
		ms = get_time(time) - get_time(philo->last_eat_time);
		if (ms >= philo->info->time_to_die)
		{
		}
	}
}
