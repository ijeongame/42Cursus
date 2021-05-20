/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_wall_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 04:01:31 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 06:03:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_side(t_cub *c, t_wc *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (c->info.pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - c->info.pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (c->info.pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - c->info.pos_y) * w->delta_dist_y;
	}
}

void	wall_hit(t_cub *c, t_wc *w)
{
	while (!w->hit)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_y += w->step_y;
			w->side = 1;
		}
		if (c->map[w->map_x][w->map_y] == 1)
			w->hit = 1;
	}
}

void	wall_text_clac(t_cub *c, t_wc *w, t_text *t)
{
	t->t_x = (int)(w->wall_x * (double)TEXTW);
	if (w->side == 0 && w->ray_dir_x > 0)
		t->t_x = TEXTW - t->t_x - 1;
	if (w->side == 1 && w->ray_dir_y < 0)
		t->t_x = TEXTW - t->t_x - 1;
	if (w->side == 0)
	{
		if (w->ray_dir_x < 0)
			t->t_num = NO;
		else
			t->t_num = SO;
	}
	else
	{
		if (w->ray_dir_y < 0)
			t->t_num = WE;
		else
			t->t_num = EA;
	}
	t->t_pos = (w->draw_start - c->tid.s_height / 2 + w->line_h) * w->step;
}

void	wall_text_init(t_cub *c, t_wc *w)
{
	if (!w->side)
		w->perp_w_dist = \
		(w->map_x - c->info.pos_x + (1 - w->step_x) / 2) / w->ray_dir_x;
	else
		w->perp_w_dist = \
		(w->map_y - c->info.pos_y + (1 - w->step_y) / 2) / w->ray_dir_y;
	w->line_h = (int)(c->tid.s_height / w->perp_w_dist);
	w->draw_start = (c->tid.s_height / 2) - (w->line_h / 2);
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = (c->tid.s_height / 2) + (w->line_h / 2);
	if (w->draw_end >= c->tid.s_height)
		w->draw_end = c->tid.s_height - 1;
	if (w->side == 0)
		w->wall_x = c->info.pos_y + w->perp_w_dist * w->ray_dir_y;
	else
		w->wall_x = c->info.pos_x + w->perp_w_dist * w->ray_dir_x;
	w->wall_x -= floor(w->wall_x);
	w->step = 1.0 * TEXTH / w->line_h;
}

void	wall_text(t_cub *c, t_wc *w, int x)
{
	t_text	t;
	int		y;

	wall_text_init(c, w);
	wall_text_clac(c, w, &t);
	y = w->draw_start - 1;
	while (++y < w->draw_end)
	{
		t.t_y = (int)t.t_pos & (TEXTH - 1);
		t.t_pos += w->step;
		t.color = c->info.texture[t.t_num][TEXTH * t.t_y + t.t_x];
		c->info.buffer[y][x] = t.color;
	}
}
