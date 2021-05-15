/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:11:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/16 04:20:29 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fill(t_cub *c, int x, int y, int color)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i++ < TILE_SIZE)
	{
		j = 0;
		while (j++ <TILE_SIZE)
			c->img.data[(x + i) * c->tid.m_width + y + j] = color;
	}
}

void	draw_rect(t_cub *c)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < c->tid.m_height)
	{
		j = 0;
		while (j++ < c->tid.m_width)
		{
			if (c->map[i][j])
				draw_fill(c, i, j, 0xffffff);
			else if(c->map[i][j] > 2)
				draw_fill(c, i, j, 0xcdabef);
		}
	}
}

void	cub_draw(t_cub *c)
{
	int		i;
	int		j;
	int		a;
	int		b;

	draw_rect(c);
	i = c->info.pos_x * TILE_SIZE;
	j = c->info.pos_y * TILE_SIZE;
	a = -1;
	while (++a < 2)
	{
		b = -1;
		while (++b < 2)
			c->img.data[(i + a) * c->tid.s_width + (j + b)] = 0xf0f0f0;
	}

}
