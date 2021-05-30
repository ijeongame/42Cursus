/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:10 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:30:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_link **b, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->b_size < 2)
		return ;
	tmp = (*b)->val;
	link = move_link_tail(*b);
	link->next = new_link_tail(link, tmp);
	delete_link(b);
}
