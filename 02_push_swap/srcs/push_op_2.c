/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/24 23:48:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_lst **a, t_lst **b, t_info *info)
{
	t_lst	*node;
	long	tmp;

	node = *b;
	if (!node)
		return ;
	tmp = node->val;
	if (!node->prev)
		b = 0;
	else
		b = node->prev;
	lst_free(node);
	if (!*(*a))
		new_lst(*a);


}

void	op_pb(t_lst **a, t_lst **b, t_info *info)
{

}
