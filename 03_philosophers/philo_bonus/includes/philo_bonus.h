/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:44:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/08/04 23:38:13 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

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
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_must_eat;
	int			finish;
	int			start_time;
	int			print_died;
	sem_t		*fork;
	sem_t		*full;
	sem_t		*died;
	sem_t		*text;
	t_philo		*philo;
};

struct s_philo
{
	int			n;
	int			eat_cnt;
	int			philo_died;
	int			last_eat_time;
	char		*name;
	pid_t		pid;
	sem_t		*eating;
	t_info		*info;
};

char	*ft_strdup(const char *src);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		init_philo(t_info *info, int ac, char *av[]);
int		init_sem(t_info *info);

void	*monitor(void *arg);
void	*monitor_full(void *arg);
void	*monitor_died(void *arg);

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

int		ft_thread_util(pthread_t *thread, void *func, void *arg);
char	*make_sem_name(t_philo *philo);
int		get_time(void);

int		print_error(char *str);
// void	print_full(t_info *info);
void	print_died(t_philo *philo);
void	print_msg(t_philo *philo, int status);

#endif
