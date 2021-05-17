/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:16:11 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:58:37 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_count(t_cub *c, int i, int j, int *k)
{
	c->sp[*k].x = i - 1 + 0.5;
	c->sp[*k].y = j - 1 + 0.5;
	(*k)++;
}

void	map_valid_init(t_cub *c, int ***check)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	if (!(c->sp = \
	(t_sprite *)malloc(sizeof(t_sprite) * c-> tid.sprite_num)))
		return ;
	while (++i < c->tid.m_height + 2)
	{
		j = -1;
		while (++j < c->tid.m_width + 2)
		{
			if (i * j == 0 || \
			i == c->tid.m_height + 1 || j == c->tid.m_width + 1)
				(*check)[i][j] = -1;
			else
			{
				(*check)[i][j] = c->map[i - 1][j - 1];
				if (c->map[i - 1][j - 1] == 2 || c->map[i - 1][j - 1] == 3)
					sprite_count(c, i, j, &k);
			}

		}
	}
}

int		is_road(t_cub *c, int x, int y, int ***check)
{
	int		dir_x[4];
	int		dir_y[4];
	int		i;

	dir_x[0] = -1;
	dir_x[1] = 0;
	dir_x[2] = 1;
	dir_x[3] = 0;
	i = -1;
	while (++i < 4)
		dir_y[3 - i] = dir_x[x];
	i = -1;
	if ((*check)[x][y] == 1 || (*check)[x][y] == 2)
		return (1);
	if ((*check)[x][y] == -1)
		return (0);
	(*check)[x][y] = -2;
	i = -1;
	while (++i < 4)
		if (!is_road(c, x + dir_x[i], y + dir_y[i], check))
			return (0);
	return (1);
}

int		is_map(t_cub *c, int **check)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = -1;
	while (++i < c->tid.m_height)
	{
		j = -1;
		while (++j < c->tid.m_width)
		{
			if (check[i][j] == 0)
			{
				res = 1;
				if (!is_road(c, i, j, &check))
					return (0);
			}
		}
	}
	if (!res)
		return (0);
	else
		return (1);
}

int		map_valid(t_cub *c)
{
	int		**check;
	int		i;
	int		res;

	check = (int **)malloc(sizeof(int *) * (c->tid.m_height + 2));
	i = -1;
	while (++i < c->tid.m_height + 2)
		check[i] = (int *)malloc(sizeof(int) * (c->tid.m_width + 2));
	map_valid_init(c, &check);
	res = is_map(c, check);
	i = -1;
	while (++i < c->tid.m_height + 2)
		free(check[i]);
	free(check);
	return (res);
}
