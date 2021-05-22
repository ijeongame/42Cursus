/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:17:57 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 17:41:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_value(t_cub *c)
{
	c->key.key_w = 0;
	c->key.key_a = 0;
	c->key.key_s = 0;
	c->key.key_d = 0;
	c->key.key_left = 0;
	c->key.key_right = 0;
	c->key.key_esc = 0;
	c->info.m_speed = 0.05;
	c->info.r_speed = 0.05;
}

int		set_buf(t_cub *c)
{
	int		i;
	int		j;

	if (!(c->info.buffer = (int **)malloc(sizeof(int *) * c->tid.s_height)))
		return (-1);
	i = -1;
	while (++i < c->tid.s_height)
	{
		if (!(c->info.buffer[i] = (int *)malloc(sizeof(int) * c->tid.s_width)))
			return (-1);
	}
	i = -1;
	while (++i < c->tid.s_height)
	{
		j = -1;
		while (++j < c->tid.s_width)
		{
			c->info.buffer[i][j] = 0;
		}
	}
	return (1);
}

int		set_text(t_cub *c)
{
	int		i;
	int		j;

	if (!(c->info.texture = (int **)malloc(sizeof(int *) * TEXT)))
		return (-1);
	i = -1;
	while (++i < TEXT)
	{
		if (!(c->info.texture[i] = \
		(int *)malloc(sizeof(int) * (TEXTH * TEXTW))))
			return (-1);
	}
	i = -1;
	while (++i < TEXT)
	{
		j = -1;
		while (++j < TEXTH * TEXTW)
		{
			c->info.texture[i][j] = 0;
		}
	}
	return (1);
}

int		cub_init(t_cub *c)
{
	set_value(c);
	if (set_buf(c) < 0)
		return (-1);
	if (set_text(c) < 0)
		return (-1);
	if (!(c->info.z_buffer = malloc(sizeof(double) * c->tid.s_width)))
		return (-1);
	c->win = \
	mlx_new_window(c->mlx, c->tid.s_width, c->tid.s_height, "cub3d");
	c->img.img = \
	mlx_new_image(c->mlx, c->tid.s_width, c->tid.s_height);
	c->img.data = \
	(int *)mlx_get_data_addr(c->img.img, &c->img.bpp, \
	&c->img.size_l, &c->img.endian);
	return (1);
}
