/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:18:32 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/16 16:37:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += *str++ - '0';
	}
	return (res * sign);
}

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
	else if (status == DIED)
		printf("%s\n", " : is died");
}

void	print_msg(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->info->text);
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->text);
		return ;
	}
	printf("%d", get_time() - philo->info->start_time);
	if (status == FULL)
		printf("%s\n", "\tall philosophers take the meals");
	else
		print_status(philo, status);
	pthread_mutex_unlock(&philo->info->text);
}
