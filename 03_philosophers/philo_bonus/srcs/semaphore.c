/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:35:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/25 20:28:31 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int 	init_sem(t_info *info)
{
	int			i;
	int			status;
	pthread_t	thread;

	if (pthread_create(&thread, NULL, check_full, info))
		return (1);
	pthread_detach(thread);
	i = -1;
	info->start_time = get_time();
	while (++i < info->num_of_philo)
	{
		info->philo[i].last_eat_time = get_time();
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
			return (philo(&info->philo[i]));
		else if (info->philo[i].pid < 0)
			print_error("error : fork failed\n");
	}
	i = -1;
	while (++i < info->num_of_philo)
		waitpid(info->philo[i].pid, status, 0);
	return (0);
}