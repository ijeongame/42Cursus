/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:22:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 03:39:48 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_find_pos(t_link *link, t_info *info)
{
	while (link)
	{
		if (link->val == info->min)
			break ;
		info->pos++;
		link = link->next;
	}
}

void	algo_find_min(t_link *link, t_info *info, int cnt)
{
	info->min = link->val;
	while (cnt--)
	{
		if (info->min > link->val)
			info->min = link->val;
		else
			info->min = info->min;
		link = link->next;
	}
}

void	algo_find_max(t_link *link, t_info *info, int cnt)
{
	info->max = link->val;
	while (cnt--)
	{
		if (info->max < link->val)
			info->max = link->val;
		else
			info->max = info->max;
		link = link->next;
	}
}

void	algo_pivot(t_link *link, t_info *info, int cnt)
{
	algo_find_min(link, info, cnt);
	algo_find_max(link, info, cnt);
	if ((info->max - info->min) == 1)
		info->pivot = info->max;
	else
		info->pivot = ((info->min + info->max) / 2);
}
