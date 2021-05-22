/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:42:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 14:47:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_free(t_cub *c)
{
	int		i;

	if (c->info.buffer)
	{
		i = -1;
		while (++i < c->tid.s_height)
			free(c->info.buffer[i]);
		free(c->info.buffer);
	}
	if (c->info.texture)
	{
		i = -1;
		while (++i < TEXT)
			free(c->info.texture[i]);
		free(c->info.texture);
	}
	if (c->map)
	{
		i = -1;
		while (++i < c->tid.m_height)
			free(c->map[i]);
		free(c->map);
	}
}

int			err_msg(char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	return (0);
}

void		exit_cub3d(t_cub *c)
{
	if (c->win)
		mlx_destroy_window(c->mlx, c->win);
	if (c->img.img)
		mlx_destroy_image(c->mlx, c->img.img);
	set_free(c);
	system("killall afplay");
	system("leaks cub3D");
	exit(0);
}

void		cub_exit(t_cub *c, char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit_cub3d(c);
}
