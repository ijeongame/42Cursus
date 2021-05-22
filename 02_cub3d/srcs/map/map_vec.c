/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:17:41 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 21:16:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dir(t_cub *c, double dir_x, double dir_y)
{
	c->info.dir_x = dir_x;
	c->info.dir_y = dir_y;
}

void	set_plane(t_cub *c, double plane_x, double plane_y)
{
	c->info.plane_x = plane_x;
	c->info.plane_y = plane_y;
}

void	set_pos(t_cub *c, char pos, int i, int j)
{
	if (pos == 'N')
	{
		set_dir(c, -1, 0);
		set_plane(c, 0, 0.66);
	}
	if (pos == 'S')
	{
		set_dir(c, 1, 0);
		set_plane(c, 0, -0.66);
	}
	if (pos == 'W')
	{
		set_dir(c, 0, -1);
		set_plane(c, -0.66, 0);
	}
	if (pos == 'E')
	{
		set_dir(c, 0, 1);
		set_plane(c, 0.66, 0);
	}
	c->info.pos_x = i + 0.51;
	c->info.pos_y = j + 0.51;
}
