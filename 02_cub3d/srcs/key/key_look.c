/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:00:37 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 03:24:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_cub *c)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = c->info.dir_x;
	c->info.dir_x = c->info.dir_x * cos(c->info.r_speed) - \
	c->info.dir_y * sin(c->info.r_speed);
	c->info.dir_y = old_dir_x * sin(c->info.r_speed) + \
	c->info.dir_y * cos(c->info.r_speed);
	old_plane_x = c->info.plane_x;
	c->info.plane_x = c->info.plane_x * cos(c->info.r_speed) - \
	c->info.plane_y * sin(c->info.r_speed);
	c->info.plane_y = old_plane_x * sin(c->info.r_speed) + \
	c->info.plane_y * cos(c->info.r_speed);
}

void	key_right(t_cub *c)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = c->info.dir_x;
	c->info.dir_x = c->info.dir_x * cos(-c->info.r_speed) - \
	c->info.dir_y * sin(-c->info.r_speed);
	c->info.dir_y = old_dir_x * sin(-c->info.r_speed) + \
	c->info.dir_y * cos(-c->info.r_speed);
	old_plane_x = c->info.plane_x;
	c->info.plane_x = c->info.plane_x * cos(-c->info.r_speed) - \
	c->info.plane_y * sin(-c->info.r_speed);
	c->info.plane_y = old_plane_x * sin(-c->info.r_speed) + \
	c->info.plane_y * cos(-c->info.r_speed);
}
