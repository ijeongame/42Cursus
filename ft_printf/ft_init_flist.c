/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:17 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/02 19:09:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flag		ft_init_flag(t_flag *flag)
{
	flag->left = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->base = 0;
	flag->sign = 0;
}

t_format	*ft_init_flist(const char **format)
{
	t_format *op;

	if (!(op = malloc(sizeof(t_format))))
		return (0);
	ft_init_flag(&op->flag);
	op->width = 0;
	op->prec = 0;
	op->type = 0;
	op->len = 0;
}
