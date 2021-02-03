/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:03:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 16:20:29 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_set_list(const char **format, int cnt)
{
	t_format	*op;

	if (!(op = malloc(sizeof(t_format))))
		return (0);
	op->left = 0;
	op->zero = 0;
	op->base = 0;
	op->space = 0;
	op->sign = 0;
	op->width = 0;
	op->prec = 0;
	op->type = 0;
	op->len_h = 0;
	op->len_l = 0;
	op->cnt = cnt;
	op->str = format;
	return (op);
}

int			ft_parse_start(va_list ap, const char **format, int cnt)
{
	t_format	*op;

	if (!(op = ft_set_list(format, cnt)))
		return (-1);
	return (ft_parse_format(ap, op));
}
