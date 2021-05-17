/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:44:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:46:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_bmp(t_cub *c)
{
	c->bmp.bf_type1 = 'B';
	c->bmp.bf_type2 = 'M';
	c->bmp.bf_size = (4 * (c->tid.s_width * c->tid.s_height)) + 54;
	c->bmp.bf_reser1 = 0;
	c->bmp.bf_reser2 = 0;
	c->bmp.bf_off = 54;
	c->bmp.bi_size = 40;
	c->bmp.bi_width = c->tid.s_width;
	c->bmp.bi_height = -c->tid.s_height;
	c->bmp.bi_planes = 1;
	c->bmp.bi_count = 32;
	c->bmp.bi_compre = 0;
	c->bmp.bi_img_size = (4 * (c->tid.s_width * c->tid.s_height));
	c->bmp.bi_x_ppm = c->tid.s_width;
	c->bmp.bi_y_ppm = c->tid.s_height;
	c->bmp.bi_c_used = 0;
	c->bmp.bi_c_import = 0;
}

void	cub_bmp(t_cub *c)
{
	int		fd;

	fd = open("cud3d_save.bmp", O_RDWR | O_TRUNC | O_CREAT, 0666);
	draw_bmp(c);
	write(fd, &c->bmp, 54);
	write(fd, c->img.data, c->bmp.bi_img_size);
	close(fd);
}
