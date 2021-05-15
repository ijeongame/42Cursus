/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:22:33 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/15 04:30:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_text(t_cub *c, t_fc f, int y)
{
	t_text	t;
	int		x;

	x = -1;
	while (++x < c->tid.s_width)
	{
		t.t_x = (int)(TEXT_W * (f.floor_x - (int)f.floor_x)) & (TEXT_W - 1);
		t.t_y = (int)(TEXT_H * (f.floor_x - (int)f.floor_x)) & (TEXT_H - 1);
		f.floor_x += f.f_step_x;
		f.floor_y += f.f_step_y;
		if (c->tid.ceil_t)
			t.color = c->info.texture[CE][TEXT_W * t.t_y + t.t_x];
		else
			t.color = c->tid.ceiling;
		if (c->tid.floor_t)
			t.color = c->info.texture[FL][TEXT_W * t.t_y + t.t_x];
		else
			t.color = c->tid.floor;
		c->img.data[y * c->tid.s_width + x] = t.color;
	}
}

void	floor_init(t_cub *c, t_fc *f, int y)
{
	f->ray_dir_x0 = c->info.dir_x - c->info.plane_x;
	f->ray_dir_y0 = c->info.dir_y - c->info.plane_y;
	f->ray_dir_x1 = c->info.dir_x + c->info.plane_x;
	f->ray_dir_y1 = c->info.dir_y + c->info.plane_y;
	f->p = y - c->tid.s_height / 2;
	f->pos_z = 0.5 * c->tid.s_height;
	f->row_dist = f->pos_z / f->p;
	f->floor_x = c->info.pos_x + f->row_dist * f->ray_dir_x0;
	f->floor_y = c->info.pos_y + f->row_dist * f->ray_dir_y0;
	f->f_step_x = \
	f->row_dist * (f->ray_dir_x1 - f->ray_dir_x0) /c->tid.s_width;
	f->f_step_x = \
	f->row_dist * (f->ray_dir_x1 - f->ray_dir_x0) /c->tid.s_width;
}

void	cub_floor(t_cub *c)
{
	t_fc	f;
	int		y;

	y = -1;
	while (++y < c->tid.s_height)
	{
		floor_init(c, &f, y);
		floor_text(c, f, y);
	}
}
