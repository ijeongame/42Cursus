/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:34:36 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/31 18:32:26 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_philo(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->num_of_philo)
	{
		waitpid(info->philo[i].pid, &status, 0);
		sem_unlink(info->philo[i].name);
		sem_close(info->philo[i].eating);
		free(info->philo[i].name);
	}
	i = -1;
	while (++i < info->num_of_philo)
		sem_post(info->full);
	sem_close(info->fork);
	sem_close(info->died);
	sem_close(info->text);
	sem_close(info->full);
	free(info->philo);
}

int	main(int ac, char *av[])
{
	t_info		info;
	pthread_t	thread;

	memset(&info, 0, sizeof(info));
	if (init_philo(&info, ac, av))
		return (1);
	if (init_sem(&info))
		return (1);
	if (ft_thread_util(&thread, monitor_died, &info))
		return (1);
	free_philo(&info);
	return (0);
}
