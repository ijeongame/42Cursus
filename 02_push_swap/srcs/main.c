/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:58:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/24 21:49:38 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_sawp.h"

void	ps_start(char ***save, char ***av, t_lst *a,)
{

}

int		main(int ac, char **av)
{
	char	**save;
	t_lst	*a;
	t_lst	*b;
	t_info	*info;

	if (ac == 1)
		return (-1);
	else
		ps_start(&save, &av, &a, &info);
}
