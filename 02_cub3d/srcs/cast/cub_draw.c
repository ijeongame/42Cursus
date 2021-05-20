/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:11:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 06:23:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_rect(t_cub *c, int x, int y, int color)
// {
// 	int i;
// 	int j;

// 	x *= TILE_SIZE;
// 	y *= TILE_SIZE;
// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			c->img.data[(x + i) * c->tid.s_width + y + j] = color;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_all_rect(t_cub *c)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < c->tid.m_height)
// 	{
// 		j = 0;
// 		while (j < c->tid.m_width)
// 		{
// 			if (c->map[i][j] == 1)
// 				draw_rect(c, i, j, 0xffffff);
// 			else if (c->map[i][j] >= 2)
// 				draw_rect(c, i, j, 0xabcdef);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	cub_draw(t_cub *c)
// {
// 	int	i;
// 	int j;
// 	int	a;
// 	int	b;

// 	draw_all_rect(c);
// 	i = c->info.pos_x * TILE_SIZE;
// 	j = c->info.pos_y * TILE_SIZE;
// 	a = -1;
// 	while (++a < 2)
// 	{
// 		b = -1;
// 		while (++b < 2)
// 			c->img.data[(i + a) * c->tid.s_width + (j + b)] = 0xff0000;
// 	}
// }

void	cub_draw(t_cub *c)
{
	int		i;
	int		j;
	int		line;

	line = c->img.size_l / (c->img.bpp / 8);
	i = -1;
	while (++i < c->tid.s_height)
	{
		j = -1;
		while (++j < c->tid.s_width)
			c->img.data[i * line + j] = c->info.buffer[i][j];
	}
	mlx_put_image_to_window(c->mlx, c->win, c->img.img, 0, 0);
}

