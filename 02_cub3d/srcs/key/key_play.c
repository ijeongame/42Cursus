/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:46:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 02:50:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_play(t_cub *c)
{
	if (c->key.key_w)
		key_w(c);
	if (c->key.key_s)
		key_s(c);
	if (c->key.key_a)
		key_a(c);
	if (c->key.key_d)
		key_d(c);
	if (c->key.key_left)
		key_left(c);
	if (c->key.key_right)
		key_right(c);
}
