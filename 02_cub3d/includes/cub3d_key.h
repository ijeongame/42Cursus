/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:59:39 by hkwon             #+#    #+#             */
/*   Updated: 2021/04/30 02:19:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_KEY_H
# define CUB3D_KEY_H

# include "cub3d.h"

int		event_key_press(int keycode, t_cub *cub);
int		event_key_release(int keycode, t_cub *cub);
int		event_exit(int keycode, t_cub *cub);

#endif
