/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/05 21:28:18 by hkwon            ###   ########.fr       */
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

typedef struct s_info
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					finish;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}						t_info;

typedef struct s_philo
{
	int					n;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	t_info				*info;
}						t_philo;

int			start_philo(t_info *info, int ac, char *av[]);

int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);

#endif
