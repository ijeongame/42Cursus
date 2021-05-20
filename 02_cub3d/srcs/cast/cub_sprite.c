/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:10:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 07:42:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_init(t_cub *c, t_sc *s, int i)
{
	s->sp_x = c->sp[s->sp_order[i]].x - c->info.pos_x;
	s->sp_y = c->sp[s->sp_order[i]].y - c->info.pos_y;
	s->sp_dev = 1.0 / (c->info.plane_x * c->info.dir_y - \
	c->info.plane_y * c->info.dir_x);
	s->trans_x = s->sp_dev * (c->info.dir_y * s->sp_x - \
	c->info.dir_x * s->sp_y);
	s->trans_y = s->sp_dev * (-c->info.plane_y * s->sp_x + \
	c->info.plane_x * s->sp_y);
	s->sp_screen_x = (int)((c->tid.s_width / 2) * \
	(1 + s->trans_x / s->trans_y));
}

void	cub_sprite(t_cub *c)
{
	t_sc	s;
	int		i;

	sprite_sort(c, &s);
	i = -1;
	while (++i < c->tid.sprite_num)
	{
		sprite_init(c, &s, i);
		sprite_text(c, &s);
	}
	if (s.sp_order)
		free(s.sp_order);
	if (s.sp_dist)
		free(s.sp_dist);
}
