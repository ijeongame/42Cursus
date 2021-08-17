/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/08/17 17:10:41 by kwonhyukbae      ###   ########.fr       */
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

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define FULL 6

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_info
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					finish;
	int					start_time;
	pthread_mutex_t		*fork;
	pthread_mutex_t		text;
	t_philo				*philo;
};

struct s_philo
{
	int				n;
	int				eat_cnt;
	int				fork_l;
	int				fork_r;
	int				last_eat_time;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_info			*info;
};

int		init_philo(t_info *info, int ac, char *av[]);
int		init_thread(t_info *info);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
int		get_time(void);
int		print_error(char *str);
void	print_msg(t_philo *philo, int status);
int		ft_atoi(const char *str);

#endif
