/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:36:38 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/31 18:36:39 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	fork_on(t_philo *philo)
{
	sem_wait(philo->info->fork);
	print_msg(philo, FORK);
	sem_wait(philo->info->fork);
	print_msg(philo, FORK);
}

void	fork_off(t_philo *philo)
{
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
}

void	eating(t_philo *philo)
{
	fork_on(philo);
	sem_wait(philo->eating);
	print_msg(philo, EATING);
	philo->last_eat_time = get_time();
	while (get_time() - philo->last_eat_time <= \
	philo->info->time_to_eat && !philo->info->finish)
		usleep(1000);
	sem_post(philo->eating);
	philo->eat_cnt++;
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
