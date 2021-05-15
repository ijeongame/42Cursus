/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 01:20:02 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/16 04:33:00 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_cub *c, int t_num, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = \
	mlx_xpm_file_to_image(c->mlx, path, &img.width, &img.height);
	if (!img.img)
		cub_exit(&c, "image error");
	img.data = \
	(int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x <img.width)
			c->info.texture[t_num][img.width * y + x] = \
			img.data[img.width * y + x];
	}
	mlx_destroy_image(c->mlx, img.img);
}

void	cub_load_texture(t_cub *c)
{
	load_image(c, NO, c->tid.no_path);
	load_image(c, SO, c->tid.so_path);
	load_image(c, WE, c->tid.we_path);
	load_image(c, EA, c->tid.ea_path);
	if (c->tid.floor_t)
		load_image(c, FL, c->tid.fl_path);
	if (c->tid.ceil_t)
		load_image(c, CE, c->tid.ce_path);
	load_image(c, SP, c->tid.sp_path)
}
