/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:51:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 01:05:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_color(char *line)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(line) * 256 * 256;
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (-1);
	}
	g = ft_atoi(line) * 256;
	while (*line != ',' && *line)
	{
		line++;
		if (!(*line))
			return (-1);
	}
	if (!(*line))
		return (-1);
	b = ft_atoi(line);
	return (r + g + b);
}
