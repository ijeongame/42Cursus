/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:34:27 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 20:28:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_atoi(char **str)
{
	int	res;

	res = 0;
	while (**str && ft_isdigit(**str))
	{
		res *= 10;
		res += **str - '0';
		(*str)++;
	}
	return (res);
}

int		map_color(char *line)
{
	int		r;
	int		g;
	int		b;

	r = color_atoi(&line);
	if (*line != ',')
		return (-1);
	line++;
	g = color_atoi(&line);
	if (*line != ',')
		return (-1);
	line++;
	b = color_atoi(&line);
	if (*line)
		return (-1);
	if (r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r * 256 * 256) + (g * 256) + b);
}

int		map_ceiling(t_cub *c, char *line)
{
	int		tmp;

	if (ft_isdigit(*line))
	{
		c->tid.ceil_t = 0;
		c->tid.ceiling = map_color(line);
		if ((tmp = c->tid.ceiling) < 0)
			return (0);
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
			return (0);
	}
	else
	{
		c->tid.floor_t = 1;
		c->tid.fl_path = ft_strdup(line);
	}
	return (1);
}
