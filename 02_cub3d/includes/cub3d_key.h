/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:59:39 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/18 04:04:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_KEY_H
# define CUB3D_KEY_H

# include "cub3d.h"

int		event_key_press(int keycode, t_cub *cub);
int		event_key_release(int keycode, t_cub *cub);
int		event_exit(t_cub *cub);

#endif
