/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:27:41 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/16 19:03:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int 	ft_thread_util(pthread_t *thread, void *func, void *av)
{
	if (pthread_create(thread, NULL, func, av))
		return (1);
	pthread_detach(*thread);
	return (0);
}

sem_t	*ft_sem_init(
	const char *name,
	unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	make_sem_name(t_philo *philo)
{
	char	*name;

	name = ft_strdup("sem_name");
	philo->name = ft_strjoin(name, ft_itoa(philo->n));
}
