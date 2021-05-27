/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:09 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 19:36:34 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_link **a, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->a_size < 2)
		return ;
	tmp = (*a)->val;
	link = move_link_tail(*a);
	link->next = new_link_tail(link, tmp);
	delete_link(a);
	write(1, "ra\n", 3);
}
