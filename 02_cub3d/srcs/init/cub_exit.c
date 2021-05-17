/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:42:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 04:52:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	system("leadks cub3D");
	exit(0);
}

void		cub_exit(t_cub *c, char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit_cub3d(c);
}
