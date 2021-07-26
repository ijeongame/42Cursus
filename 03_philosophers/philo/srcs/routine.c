/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:30:30 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/26 22:30:31 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_on(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
	print_msg(philo, FORK);
}

void	fork_off(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
}

void	eating(t_philo *philo)
{
	fork_on(philo);
	pthread_mutex_lock(&philo->mutex);
	print_msg(philo, EATING);
	philo->last_eat_time = get_time();
	while (get_time() - philo->last_eat_time <= philo->info->time_to_eat
	&& !philo->info->finish)
		usleep(1000);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->mutex);
	fork_off(philo);
}

void	sleeping(t_philo *philo)
{
	int	time;

	print_msg(philo, SLEEPING);
	time = get_time();
	while (get_time() - time <= philo->info->time_to_sleep \
	&& !philo->info->finish)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}

