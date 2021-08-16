/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:44:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/08/16 19:45:24 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_init(
	const char *name,
	unsigned int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

static void	get_arg(t_info *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_must_eat = ft_atoi(av[5]);
	else
		info->num_must_eat = -1;
}

static int	check_arg(t_info *info, int ac)
{
	if (info->num_of_philo < 0 || info->num_of_philo > 200)
		return (print_error("error : wrong num of philo\n"));
	if (info->time_to_die < 60)
		return (print_error("error : wrong time to die\n"));
	if (info->time_to_eat < 60)
		return (print_error("error : wrong time to eat\n"));
	if (info->time_to_sleep < 60)
		return (print_error("error : wrong time to sleep\n"));
	if (ac == 6 && info->num_must_eat < 0)
		return (print_error("error : worng num\n"));
	return (0);
}

static int	set_philo(t_info *info)
{
	int	i;

	info->fork = ft_sem_init("fork", info->num_of_philo);
	info->full = ft_sem_init("full", 0);
	info->died = ft_sem_init("died", 0);
	info->text = ft_sem_init("text", 1);
	info->philo = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!info->philo)
		return (print_error("ERROR: malloc failed\n"));
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].n = i;
		info->philo[i].eat_cnt = 0;
		info->philo[i].name = make_sem_name(&info->philo[i]);
		info->philo[i].eating = ft_sem_init(info->philo[i].name, 1);
		info->philo[i].info = info;
	}
	return (0);
}

int	init_philo(t_info *info, int ac, char *av[])
{
	get_arg(info, ac, av);
	if (check_arg(info, ac))
		return (1);
	if (set_philo(info))
		return (1);
	return (0);
}
