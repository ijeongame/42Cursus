/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:18:32 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/08 20:19:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(struct timeval	time)
{
	long long	ms;

	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	print_philo(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	time;

	pthread_mutex_lock(&philo->info->fin_mutex);
	gettimeofday(&time, NULL);
	ms = get_time(time) - get_time(philo->info->start_time);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	pthread_mutex_unlock(&philo->info->fin_mutex);
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
