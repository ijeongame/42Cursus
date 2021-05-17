/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ceiling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:47:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/17 02:46:36 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_resolution(t_cub *c)
{
	int		w_size;
	int		h_size;

	mlx_get_screen_size(c->mlx, &w_size, &h_size);
	if (c->tid.s_width > w_size)
		c->tid.s_width = w_size;
	else
		c->tid.s_width = c->tid.s_width;
	if (c->tid.s_height > h_size)
		c->tid.s_height = h_size;
	else
		c->tid.s_height = c->tid.s_height;
	if (c->tid.s_width < 600)
		c->tid.s_width = 600;
	if (c->tid.s_height < 500)
		c->tid.s_height = 500;
}
