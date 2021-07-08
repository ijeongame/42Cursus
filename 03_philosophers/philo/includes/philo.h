/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/08 22:06:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_info
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					must_eat_cnt;
	int					finish;
	pthread_mutex_t		*fork;
	pthread_mutex_t		fin_mutex;
	struct timeval		start_time;
	t_philo				*philo;
};

struct s_philo
{
	int				n;
	int				eat_cnt;
	int				fork_l;
	int				fork_r;
	pthread_mutex_t	eat_mutex;
	pthread_t		thread;
	struct timeval	last_eat_time;
	t_info			*info;
};

int			init(t_info *info, int ac, char *av[]);
void		*philo(void *av);
void		*monitor(void *av);
void		*monitor_must_eat(void *av);
void		print_philo(t_philo *philo, char *str);
int			ft_atoi(const char *str);
long long	get_time(struct timeval	time);

#endif
