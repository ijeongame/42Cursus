/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:30:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/16 04:12:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"
# include "cub3d_struct.h"
# include "cub3d_key.h"
# include "cub3d_linux.h"
# include "cub3d_mac.h"

# define ERROR	1
# define SUCESS	0

int		cub_init(t_cub *c);
void	cub_load_texture(t_cub *c);

void	key_play(t_cub *c);
void	key_w(t_cub *c);
void	key_s(t_cub *c);
void	key_a(t_cub *c);
void	key_d(t_cub *c);

void	cub_floor(t_cub *c);

void	cub_wall(t_cub *c);
void	wall_side(t_cub *c, t_wc *w);
void	wall_hit(t_cub *c, t_wc *w);
void	wall_text(t_cub *c, t_wc *w, int x);

void	cub_sprite(t_cub *c);
void	strite_sort(t_cub *c, t_sc *s);
void	sprite_text(t_cub *c, t_sc *s, int i);

void	cub_draw(t_cub *c);

#endif
