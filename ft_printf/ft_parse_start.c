/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:03:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 22:41:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_set_list(const char **format)
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
	op->prec = -1;
	op->type = 0;
	op->len_h = 0;
	op->len_l = 0;
	op->str = format;
	return (op);
}

int			ft_parse_format(va_list ap, t_format *op)
{
	if (ft_strchr("-0# +", **op->str))
		ft_parse_flag(ap, op);
	if (ft_strchr("123456789*", **op->str))
		ft_parse_width(ap, op);
	if (ft_strchr(".", **op->str))
		ft_parse_prec(ap, op);
	if (ft_strcht("lh", **op->str))
		ft_parse_extend(ap, op);
	if (ft_strchr("cspdiuxX%", **op->str))
		ft_parse_type(ap, op);
	return (0);
}

int			ft_parse_start(va_list ap, const char **format)
{
	t_format	*op;

	if (!(op = ft_set_list(format)))
		return (-1);
	return (ft_parse_format(ap, op));
}
