/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/05 22:52:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (0);
	memset(&info, 0, sizeof(info));
	if (init(&info, ac, av))
		return (0);
	init_thread(&info);
}
