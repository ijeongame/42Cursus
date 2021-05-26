/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:32:10 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/27 00:04:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_link **b, t_info *info)
{
	t_link	*link;
	long	tmp;

	if (info->b_size < 0)
		return ;
	tmp = (*b)->val;
	link = move_stat(*b);
	link->prev = new_link_head(link, tmp);
	delete_link(b);
}
