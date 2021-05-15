/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:17:57 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/15 01:48:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_init(t_cub *c)
{
	c->key.key_w = 0;
	c->key.key_a = 0;
	c->key.key_s = 0;
	c->key.key_d = 0;
	// cub->key.key_up = 0;
	// cub->key.key_down = 0;
	c->key.key_left = 0;
	c->key.key_right = 0;
	c->key.key_esc = 0;
	c->info.m_speed = 0.05;
	c->info.r_speed = 0.05;
}

int		cub_init(t_cub *c)
{
	set_init(c);
	if (!(c->info.z_buffer = malloc(sizeof(double) * c->tid.s_width)))
		return (-1);
	c->win = \
	mlx_new_window(c->mlx, c->tid.s_width, c->tid.s_height, "cub3d");
	c->img.img = \
	mlx_new_image(c->mlx, c->tid.s_width, c->tid.s_height);
	c->img.data = \
	(int *)mlx_get_data_addr(c->img.img, &c->img.bpp, &c->img.size_l, &c->img.endian);
	return (1);
}
