/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/14 17:39:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_info *info)
{
	int		i;

	i = -1;
	usleep(2000);
	pthread_mutex_destroy(&info->text);
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork[i]);
	free(info->philo);
	free(info->fork);
}

int	main(int ac, char *av[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (init_philo(&info, ac, av))
		return (1);
	if (init_thread(&info))
		return (1);
	free_philo(&info);
	return (0);
}
