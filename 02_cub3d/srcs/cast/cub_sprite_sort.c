/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 04:14:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:59:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_sort(t_cub *c, t_sc *s)
{
	int		i;
	int		j;
	int		tmp_o;
	double	tmp_d;
	double	max;

	i = -1;
	while (++i < c->tid.sprite_num - 1)
	{
		max = s->sp_dist[i];
		j = i;
		while (++j < c->tid.sprite_num)
		{
			if (max <= s->sp_dist[j])
			{
				max = s->sp_dist[j];
				tmp_o = s->sp_order[i];
				s->sp_order[i] = s->sp_order[j];
				s->sp_order[j] = tmp_o;
				tmp_d = s->sp_dist[i];
				s->sp_dist[i] = s->sp_dist[j];
				s->sp_dist[j] = tmp_d;
			}
		}
	}
}

void	sprite_sort(t_cub *c, t_sc *s)
{
	int	i;

	if (!(s->sp_order = (int *)malloc(sizeof(int) * c->tid.sprite_num)))
		return ;
	if (!(s->sp_dist = (double *)malloc(sizeof(double) * c->tid.sprite_num)))
		return ;
	i = -1;
	while (++i < c->tid.sprite_num)
	{
		s->sp_order[i] = i;
		s->sp_dist[i] = ((c->info.pos_x - c->sp[i].x) * \
		(c->info.pos_x - c->sp[i].x)) + \
		((c->info.pos_y - c->sp[i].y) * \
		(c->info.pos_y - c->sp[i].y));
	}
	select_sort(c, s);
}
