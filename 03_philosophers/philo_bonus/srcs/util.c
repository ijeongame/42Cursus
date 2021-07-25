/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:27:41 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/25 20:42:27 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

sem_t	*ft_sem_init(
	const char *name,
	unsigned int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	make_sem_name(t_philo *philo)
{
	char	*name;

	name = ft_strdup("sem_name");
	philo->name = ft_strjoin(name, ft_itoa(philo->n));
}
