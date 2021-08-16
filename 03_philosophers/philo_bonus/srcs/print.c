/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:18:32 by hkwon             #+#    #+#             */
/*   Updated: 2021/08/16 20:26:50 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(char *str)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(2, str, i);
	return (1);
}

void	print_status(t_philo *philo, int status)
{
	printf("%s", "\tPhilosopher ");
	printf("%d", philo->n + 1);
	if (status == FORK)
		printf("%s\n", " : has taken a fork");
	else if (status == EATING)
		printf("%s\n", " : is eating");
	else if (status == SLEEPING)
		printf("%s\n", " : is sleeping");
	else if (status == THINKING)
		printf("%s\n", " : is thinking");
}

void	print_died(t_philo *philo)
{
	printf("%d", get_time() - philo->info->start_time);
	printf("%s", "\tPhilosopher ");
	printf("%d", philo->n + 1);
	printf("%s\n", " : is died");
}

void	print_msg(t_philo *philo, int status)
{
	sem_wait(philo->info->text);
	if (philo->info->finish)
	{
		sem_post(philo->info->text);
		sem_post(philo->info->fork);
		sem_post(philo->info->fork);
		return ;
	}
	printf("%d", get_time() - philo->info->start_time);
	print_status(philo, status);
	sem_post(philo->info->text);
}
