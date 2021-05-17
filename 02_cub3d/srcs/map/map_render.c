/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:18:04 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 03:48:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_change(t_cub *c, int **map, char *tmp, int i)
{
	int		j;
	int		k;

	j = -1;
	while (++j < c->tid.m_width)
		(*map)[j] = -1;
	j = -1;
	k = 0;
	while (tmp[++j] != 0)
	{
		if (tmp[j] == 'N' || tmp[j] == 'E' || \
		tmp[j] == 'W' || tmp[j] == 'S')
		{
			set_pos(c, tmp[j], i, j);
			tmp[j] = '0';
			k = 1;
		}
		if (tmp[j] == ' ')
			(*map)[j] = -1;
		else
			(*map)[j] = tmp[j] - '0';
		if (*map[j] == 2 || (*map)[j] == 3)
			c->tid.sprite_num++;
	}
	return (k);
}

void	map_size(t_cub *c, int fd, int fd2, char **line)
{
	int		tmp_size;

	c->tid.m_height = 0;
	c->tid.m_width = 0;
	tmp_size = ft_strlen(*line);
	if (c->tid.m_width < tmp_size)
		c->tid.m_width = tmp_size;
	c->tid.m_height++;
	write(fd2, *line, tmp_size);
	write(fd2, "\n", 1);
	free(*line);
	while (get_next_line(fd, line) > 0)
	{
		tmp_size = ft_strlen(*line);
		if (c->tid.m_width < tmp_size)
			c->tid.m_width = tmp_size;
		c->tid.m_height++;
		write(fd2, *line, tmp_size);
		write(fd2, "\n", 1);
		free(*line);
	}
}

void	map_malloc(t_cub *c)
{
	int		i;

	i = -1;
	c->tid.sprite_num = 0;
	c->map = (int **)malloc(sizeof(int *) * c->tid.m_height);
	while (++i < c->tid.m_height)
		c->map[i] = (int *)malloc(sizeof(int) * c->tid.m_width);
}

int		map_render(t_cub *c, int fd, char **line)
{
	int		i;
	int		j;
	int		fd_tmp;
	char	*tmp;

	j = 0;
	fd_tmp = open("tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	map_size(c, fd, fd_tmp, line);
	map_malloc(c);
	close(fd);
	close(fd_tmp);
	fd_tmp = open("tmp", O_RDONLY);
	i = 0;
	while ((get_next_line(fd_tmp, &tmp) > 0))
	{
		j += map_change(c, &(c->map[i]), tmp, i);
		i++;
		free(tmp);
	}
	if (j != 1)
		cub_exit(c, "no pos");
	free(tmp);
	close(fd_tmp);
	return (1);
}
