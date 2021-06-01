/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:29:37 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 22:55:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op(t_link **a, t_link **b, t_info *info, char *line)
{
	if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line) || \
	!ft_strcmp("ss", line))
		check_run_swap(a, b, info, line);
	else if (!ft_strcmp("ra", line) || !ft_strcmp("rb", line) || \
	!ft_strcmp("rr", line))
		check_run_rot_up(a, b, info, line);
	else if (!ft_strcmp("rra", line) || !ft_strcmp("rrb", line) || \
	!ft_strcmp("rrr", line))
		check_run_rot_down(a, b, info, line);
	else if (!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
		check_run_push(a, b, info, line);
	else
	{
		ft_putstr_fd("ERROR\n", 1);
		exit(-1);
	}
}

int		check_init(t_link **a, t_link **b, t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "\n") || !ft_strcmp(line, ""))
			break ;
		check_op(a, b, info, line);
		if (info->a_size == 0)
			break ;
		free(line);
	}
	if (line)
		free(line);
	if (!info->b_size && sort_check_a(*a, info->a_size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (1);
}
