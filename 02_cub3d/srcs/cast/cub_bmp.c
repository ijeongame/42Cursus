/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:44:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 17:54:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_header(t_cub *c, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER +
		(c->img.bpp / 8) * c->tid.s_width * c->tid.s_height;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &c->tid.s_width, 4);
	ft_memmove(&info[8], &c->tid.s_height, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &c->img.bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void	bmp_data(t_cub *c, int fd)
{
	int		x;
	int		y;
	int		line;

	line = c->img.size_l / (c->img.bpp / 8);
	y = c->tid.s_height;
	while (y-- > 0)
	{
		x = -1;
		while (++x < c->tid.s_width)
			write(fd, &c->info.buffer[y][x], (c->img.bpp / 8));
	}
}

int			cub_bmp(t_cub *c)
{
	int		fd;

	if ((fd = open("./cub_save.bmp", O_CREAT | O_RDWR, 0666)) == -1)
		cub_exit(c, "can't (create | open) image.bmp file");
	bmp_header(c, fd);
	bmp_data(c, fd);
	close(fd);
	system("leaks cub3D");
	exit(0);
}
