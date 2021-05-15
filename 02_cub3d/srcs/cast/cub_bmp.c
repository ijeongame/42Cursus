/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:44:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/16 04:33:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_bmp(t_cub *c)
{
	int		fd;

	fd = open("cud3d_save.bmp", O_RDWR | O_TRUNX | O_CREAT, 0666);
	draw_bmp(c);
	write(fd, &c->bmp, 54);
	write(fd, c->img.data, c->bmp.bi_img_size);

}
