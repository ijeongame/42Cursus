/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:44:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/25 20:48:45 by kwonhyukbae      ###   ########.fr       */
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

int		init_philo(t_info *info, int ac, char *av[]);
int		init_sem(t_info *info);
void	*check_full(void *av);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
sem_t	*ft_sem_init(
	const char *name,
	unsigned int value);
int		get_time(void);
int		print_error(char *str);
void	print_msg(t_philo *philo, int status);
int		ft_atoi(const char *str);
#endif
