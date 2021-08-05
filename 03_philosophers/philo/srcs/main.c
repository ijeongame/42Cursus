/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/08/05 14:15:40 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_info *info)
{
	int		i;

	i = -1;
	usleep(2000);
	pthread_mutex_destroy(&info->text);
	pthread_mutex_destroy(&info->philo->mutex);
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork[i]);
	free(info->philo);
	free(info->fork);
}

int	main(int ac, char *av[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (ac != 5 && ac != 6)
		return (print_error("error : wrong argument\n"));
	if (init_philo(&info, ac, av))
		return (1);
	if (init_thread(&info) < 0)
		return (1);
	free_philo(&info);
	return (0);
}
