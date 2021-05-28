/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:24:29 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/28 16:24:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_check_dup_num(t_link *link, t_link *dup)
{
	dup = link->prev;
	while (dup)
	{
		if (link->val == dup->val)
			return (0);
		if (dup->prev)
			dup = dup->prev;
		else
			break ;
	}
	return (1);
}

int		ps_check_dup(t_link *link)
{
	t_link	*dup;

	dup = 0;
	while (link)
	{
		if (link->prev)
		{
			if (!ps_check_dup_num(link, dup))
				return (0);
			link = link->prev;
		}
		else
			break ;
	}
	return (1);
}
