/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 01:48:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 07:44:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_init(t_cub *c, t_wc *w, int x)
{
	w->camera_x = 2 * x / (double)c->tid.s_width - 1;
	w->ray_dir_x = c->info.dir_x + c->info.plane_x * w->camera_x;
	w->ray_dir_y = c->info.dir_y + c->info.plane_y * w->camera_x;
	w->map_x = (int)c->info.pos_x;
	w->map_y = (int)c->info.pos_y;
	w->delta_dist_x = fabs(1 / w->ray_dir_x);
	w->delta_dist_y = fabs(1 / w->ray_dir_y);
	w->hit = 0;
}

void	cub_wall(t_cub *c)
{
	t_wc	w;
	int		x;

	x = -1;
	while (++x < c->tid.s_width)
	{
		wall_init(c, &w, x);
		wall_side(c, &w);
		wall_hit(c, &w);
		wall_text(c, &w, x);
		c->info.z_buffer[x] = w.perp_w_dist;
	}
}
