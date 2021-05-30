/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:24:29 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 14:28:36 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_check_overlap_num(t_link *link, t_link *over)
{
	over = link->prev;
	while (over)
	{
		if (link->val == over->val)
			return (0);
		if (over->prev)
			over = over->prev;
		else
			break ;
	}
	return (1);
}

int		ps_check_overlap(t_link *link)
{
	t_link	*over;

	over = 0;
	while (link)
	{
		if (link->prev)
		{
			if (!ps_check_overlap_num(link, over))
				return (0);
			link = link->prev;
		}
		else
			break ;
	}
	return (1);
}
