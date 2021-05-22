/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:58:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 18:01:51 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "cub3d_var.h"

typedef struct	s_sprite
{
	double			x;
	double			y;
}				t_sprite;

typedef struct	s_text
{
	double			t_pos;
	int				t_x;
	int				t_y;
	int				t_num;
	int				color;
}				t_text;

typedef struct	s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct	s_fc
{
	double			ray_dir_x0;
	double			ray_dir_y0;
	double			ray_dir_x1;
	double			ray_dir_y1;
	int				p;
	double			pos_z;
	double			row_dist;
	double			f_step_x;
	double			f_step_y;
	double			floor_x;
	double			floor_y;
}				t_fc;

typedef struct	s_wc
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_w_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			step;
}				t_wc;

typedef struct	s_sc
{
	int				*sp_order;
	double			*sp_dist;
	double			sp_x;
	double			sp_y;
	double			sp_dev;
	double			trans_x;
	double			trans_y;
	double			sp_screen_x;
	int				sp_h;
	int				sp_w;
	int				draw_st_x;
	int				draw_st_y;
	int				draw_end_x;
	int				draw_end_y;
}				t_sc;

typedef struct	s_tid
{
	int				s_width;
	int				s_height;
	int				m_width;
	int				m_height;
	int				sprite_num;
	int				floor_t;
	int				ceil_t;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sp_path;
	char			*fl_path;
	char			*ce_path;
	int				floor;
	int				ceiling;
}				t_tid;

typedef struct	s_info
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			m_speed;
	double			r_speed;
	double			*z_buffer;
	int				**buffer;
	int				**texture;
}				t_info;

typedef struct	s_key
{
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_esc;
}				t_key;

typedef struct	s_cub
{
	void			*mlx;
	void			*win;
	int				**map;
	int				is_bmp;
	t_info			info;
	t_img			img;
	t_key			key;
	t_tid			tid;
	t_sprite		*sp;
}				t_cub;

#endif
