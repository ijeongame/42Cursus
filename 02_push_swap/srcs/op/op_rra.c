/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:31:03 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_link **a, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->a_size < 2)
		return ;
	link = move_link_tail(*a);
	tmp = link->val;
	link->prev->next = 0;
	free(link);
	(*a)->prev = new_link_head(*a, tmp);
	(*a) = (*a)->prev;
}
