/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:12:36 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/24 23:52:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_lst *a)
{
	t_lst	*node;
	long	tmp;

	node = a;
	if (node)
	{
		if (node->prev)
		{
			node->val = tmp;
			node->val = node->prev->val;
			node->prev->val = tmp;
		}
	}
}

void	op_sb(t_lst *b)
{
	t_lst	*node;
	long	tmp;

	node  = b;
	if (node)
	{
		if (node->prev)
		{
			node->val = tmp;
			node->val = node->prev->val;
			node->prev->val = tmp;
		}
	}
}

void	op_ss(t_lst *a, t_lst *b)
{
	op_sa(a);
	op_sb(b);
}
