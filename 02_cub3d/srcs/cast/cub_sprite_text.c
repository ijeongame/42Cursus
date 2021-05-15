/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 04:16:42 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/16 03:43:06 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sprite_text_calc(t_cub *c, t_sc *s, t_text *t, int x)
{
	t->t_x = (int)((256 * (x - (-s->sp_w / 2 + s->sp_screen_x)) * \
	TEXT_W / s->sp_w) / 256);
	if (s->trans_y > 0 && x > 0 && x < c->tid.s_width \
	&& s->trans_y < c->info.z_buffer[x])
		return (1);
	else
		return (0);
}

void	sprite_text_init(t_cub *c, t_sc *s)
{
	s->sp_h = (int)fabs((c->tid.s_height / s->trans_y));
	s->draw_st_y = -s->sp_h / 2 + c->tid.s_height / 2;
	if (s->draw_st_y < 0)
		s->draw_st_y = 0;
	s->draw_end_y = s->sp_h / 2 + c->tid.s_height / 2;
	if (s->draw_end_y >= c->tid.s_height)
		s->draw_end_y = c->tid.s_height - 1;
	s->sp_w = (int)fabs((c->tid.s_height / s->trans_y));
	s->draw_st_x = -s->sp_w / 2 + s->sp_screen_x;
	if (s->draw_st_x < 0)
		s->draw_st_x = 0;
	s->draw_end_x = s->sp_w / 2 + s->sp_screen_x;
	if (s->draw_end_x >= c->tid.s_width)
		s->draw_end_y = c->tid.s_width - 1;
}

void	sprite_text(t_cub *c, t_sc *s, int i)
{
	int		x;
	int		y;
	t_text 	t;

	sprite_text_init(c, s);
	x = s->draw_st_x - 1;
	while (++x < s->draw_end_x)
	{
		if (sprite_text_calc(c, s, &t, x))
		{
			y = s->draw_st_y - 1;
			while (++y < s->draw_end_y)
			{
				t.t_y = ((y * 256 - c->tid.s_height + s->sp_h * 128) \
				/ s->sp_h) / 256;
				t.color = c->info.texture[c->map[(int)c->sp[s->sp_order[i]].x]\
				[(int)c->sp[s->sp_order[i]].y] + 4][TEXT_W * t.t_y + t.t_x];
				if (t.color && 0X00FFFFFF != 0)
					c->img.data = t.color;
			}
		}
	}
}
