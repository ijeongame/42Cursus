/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:30:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 21:20:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "cub3d_struct.h"
# include "cub3d_key.h"
# include "cub3d_var.h"

int		cub_init(t_cub *c);
void	cub_load_texture(t_cub *c);

void	key_w(t_cub *c);
void	key_s(t_cub *c);
void	key_a(t_cub *c);
void	key_d(t_cub *c);
void	key_left(t_cub *c);
void	key_right(t_cub *c);
void	key_play(t_cub *c);

void	cub_floor(t_cub *c);

void	cub_wall(t_cub *c);
void	wall_side(t_cub *c, t_wc *w);
void	wall_hit(t_cub *c, t_wc *w);
void	wall_text(t_cub *c, t_wc *w, int x);

void	cub_sprite(t_cub *c);
void	sprite_sort(t_cub *c, t_sc *s);
void	sprite_text(t_cub *c, t_sc *s);

void	cub_draw(t_cub *c);
void	cub_bmp(t_cub *c);

void	cub_exit(t_cub *c, char *msg);
void	exit_cub3d(t_cub *c);
int		err_msg(char *msg);

int		map_parse(t_cub *c, char *name);
int		map_check(t_cub *c, int fd, char **line);
int		map_floor(t_cub *c, char *line);
int		map_ceiling(t_cub *c, char *line);
void	map_resolution(t_cub *c);
int		map_render(t_cub *c, int fd, char **line);
void	set_pos(t_cub *c, char pos, int i, int j);
int		map_valid(t_cub *c);

void	set_free(t_cub *c);

void	cub_sound(void);
int		main(int ac, char **av);

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif
