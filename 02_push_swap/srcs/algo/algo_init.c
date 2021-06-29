/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:13:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 20:46:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_info *info)
{
	if (info->a_size <= 5)
		algo_less(&info->a, &info->b, info);
	else
		algo_a_to_b(info, info->a_size);
}
