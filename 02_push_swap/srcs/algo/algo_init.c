/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:13:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/28 19:01:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_link **a, t_link **b, t_info *info)
{
	t_link *head;

	algo_pivot(*a, info);

	op_ra(a, info);
	// op_pb(a, b, info);
}
