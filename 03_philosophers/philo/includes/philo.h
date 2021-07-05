/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/05 20:05:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHLIO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct			s_info
{
	int					num_of_philo;		//n명의 철학자, n개의 포크
	int					time_to_die;		//마지막 식사를 마치고 n 밀리초 안에 먹기시작하지 않거나, 시뮬레이션이 시작하고 n 밀리초 안에 먹기시작하지 않으면 죽는다.
	int					time_to_eat;		//철학자가 식사를 하는데에 걸리는 n 밀리초, 먹는 동안 철학자는 두 개의 포크를 유자해야한다.
	int					time_to_sleep;		//철학자가 잠을 자는데에 할당하는 n 밀리초.
	int					num_must_eat;		//해당인자는 선택사항, 모든 철학자가 n번을 다 먹으면 시뮬레이션 종료, 지정하지 않으면 시뮬레이션은 철학자가 죽었을때만 종료된다.
	int					finish;
	pthread_mutex_t		*fork;
	t_philo				*philo;		//info를 가지고 다니면서 philo의 정보를 들고간다.
}						t_info;

typedef struct			s_philo
{
	int					n;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	t_info				*info;		//fork만큼 할당을 해놓고 각각의 정보를 저장한다.
}						t_philo;

//srcs
int			start_philo(t_info *info, int ac, char *av[]);

//utils
int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);

#endif
