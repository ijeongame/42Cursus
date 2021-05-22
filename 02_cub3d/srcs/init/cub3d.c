/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:18:32 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 15:34:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_bmp(t_cub *c, char *av)
{
	if (!ft_strncmp(av, "--save", 6))
		c->is_bmp = 1;
	else
		cub_exit(c, "no bmp command");
}

int		main_loop(t_cub *c)
{
	int	i;

	i = -1;
	while (++i < c->tid.s_height)
		ft_memset(c->info.buffer[i], 0, sizeof(int) * c->tid.s_width);
	key_play(c);
	cub_floor(c);
	cub_wall(c);
	cub_sprite(c);
	cub_draw(c);
	if (!c->is_bmp)
	{
		mlx_put_image_to_window(c->mlx, c->win, c->img.img, 0, 0);
		mlx_do_sync(c->mlx);
	}
	else
	{
		cub_bmp(c);
		exit_cub3d(c);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_cub	c;

	ft_memset(&c, 0, sizeof(c));
	if (ac != 2 && ac != 3)
		cub_exit(&c, "check_argumant");
	c.mlx = mlx_init();
	if (ac == 3)
		check_bmp(&c, av[2]);
	else
		c.is_bmp = 0;
	if (!map_parse(&c, av[1]))
		cub_exit(&c, "map error");
	if (cub_init(&c) < 0)
		cub_exit(&c, "init error");
	cub_load_texture(&c);
	if (c.is_bmp != 1)
		cub_sound();
	mlx_hook(c.win, X_EVENT_KEY_PRESS, 0, &event_key_press, &c);
	mlx_hook(c.win, X_EVENT_KEY_RELEASE, 0, &event_key_release, &c);
	mlx_hook(c.win, X_EVENT_KEY_EXIT, 0, &event_exit, &c);
	mlx_loop_hook(c.mlx, &main_loop, &c);
	mlx_loop(c.mlx);
}
