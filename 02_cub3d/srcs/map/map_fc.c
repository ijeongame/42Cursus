/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:34:27 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:46:43 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_ceiling(t_cub *c, char *line)
{
	int		tmp;

	if (ft_isdigit(*line))
	{
		c->tid.ceil_t = 0;
		c->tid.ceiling = map_color(line);
		if ((tmp = c->tid.ceiling) < 0)
			return (err_msg("wrong color"));
	}
	else
	{
		c->tid.ceil_t = 1;
		c->tid.ce_path = ft_strdup(line);
	}
	return (1);
}

int		map_floor(t_cub *c, char *line)
{
	int		tmp;

	if (ft_isdigit(*line))
	{
		c->tid.floor_t = 0;
		c->tid.floor = map_color(line);
		if ((tmp = c->tid.floor) < 0)
			return (err_msg("wrong color"));
	}
	else
	{
		c->tid.floor_t = 1;
		c->tid.fl_path = ft_strdup(line);
	}
	return (1);
}
