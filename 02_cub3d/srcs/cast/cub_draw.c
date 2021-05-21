/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:11:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 09:14:27 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
