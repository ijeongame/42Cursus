/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:48:45 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_link **a, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->a_size < 2)
		return ;
	link = move_stat(*a);
	tmp = link->val;
	link->next->prev = 0;
	free(link);
	(*a)->next = new_link_tail(*a, tmp);
	(*a) = (*a)->next;
}
