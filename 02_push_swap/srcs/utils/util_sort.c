/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:58:15 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/29 17:09:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int		sort_check(t_link *link)
{
	while (link->next)
	{
		if (link->val > link->next->val)
			return (0);
		link = link->next;
	}
	return (1);
}
