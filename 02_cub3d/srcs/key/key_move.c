/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:00:44 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/15 01:50:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_cub *c)
{
	if (c->map\
	[(int)c->info.pos_x + c->info.dir_x * c->info.m_speed]\
	[(int)c->info.pos_y] == 0)
		c->info.pos_x += c->info.dir_x * c->info.m_speed;
	if (c->map\
	[(int)c->info.pos_x]\
	[(int)c->info.pos_y + c->info.dir_y * c->info.m_speed] == 0)
		c->info.pos_y += c->info.dir_y * c->info.m_speed;
}

void	key_s(t_cub *c)
{
	if (c->map\
	[(int)c->info.pos_x - c->info.dir_x * c->info.m_speed]\
	[(int)c->info.pos_y] == 0)
		c->info.pos_x -= c->info.dir_x * c->info.m_speed;
	if (c->map\
	[(int)c->info.pos_x]\
	[(int)c->info.pos_y - c->info.dir_y * c->info.m_speed] == 0)
		c->info.pos_y -= c->info.dir_y * c->info.m_speed;
}

void	key_a(t_cub *c)
{
	double old_dir_x;
	double old_dir_y;

	old_dir_x = c->info.dir_x * cos(M_PI_2) - c->info.dir_y * sin(M_PI_2);
	old_dir_y = c->info.dir_x * sin(M_PI_2) + c->info.dir_y * cos(M_PI_2);
	if (c->map\
	[(int)c->info.pos_x + old_dir_x * c->info.m_speed]\
	[(int)c->info.pos_y] == 0)
		c->info.pos_x += old_dir_x * c->info.m_speed;
	if (c->map\
	[(int)c->info.pos_x]\
	[(int)c->info.pos_y + old_dir_y * c->info.m_speed] == 0)
		c->info.pos_y += old_dir_y * c->info.m_speed;
}

void	key_d(t_cub *c)
{
	double old_dir_x;
	double old_dir_y;

	old_dir_x = c->info.dir_x * cos(M_PI_2) - c->info.dir_y * sin(M_PI_2);
	old_dir_y = c->info.dir_x * sin(M_PI_2) + c->info.dir_y * cos(M_PI_2);
	if (c->map\
	[(int)c->info.pos_x - old_dir_x * c->info.m_speed]\
	[(int)c->info.pos_y] == 0)
		c->info.pos_x -= old_dir_x * c->info.m_speed;
	if (c->map\
	[(int)c->info.pos_x]\
	[(int)c->info.pos_y - old_dir_y * c->info.m_speed] == 0)
		c->info.pos_y -= old_dir_y * c->info.m_speed;
}
