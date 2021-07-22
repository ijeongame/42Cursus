/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:35:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/22 18:07:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_full(void *av)
{
	t_info *info;
	int		i;

	info = av;
	i = 0;
	while (1)
	{
		sem_wait(info->full);
		if (info->finish)
			return (NULL);
		i++;
		if (i = info->num_of_philo)
			break;
	}
	print_full(FULL);
	return (NULL);
}

int 	init_sema(t_info *info)
{
	int			i;
	pthread_t	thread;

	if (ft_thread_util(&thread, check_full, info))
		return (1);
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
	return (0);
}