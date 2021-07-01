/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/01 21:58:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, int *av[])
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (0);
	info.num_of_philo = av[1];
	info.time_to_die = av[2];
	info.time_to_eat = av[3];
	info.time_to_sleep = av[4];

}
