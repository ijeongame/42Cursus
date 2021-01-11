/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/11 20:50:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_init_flag(t_flag *flag)
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
	op->prec = -1;
	return (op);
}

int		ft_parse_format(va_list ap, const char **format)
{
	t_format *op;

	if (!(op = ft_init_flist(format)))
		return (-1);
	if (ft_strchr("-0# +", **format))
		ft_parse_flag(**format, op);
	if (ft_strchr("123456789*", **format))
		ft_parse_width(ap, **format, op);
	if (ft_strchr(".", **format))
		ft_parse_prec(ap, op);
	if (ft_strchr("cspdiuxXnfgeo%", **format))
		ft_parse_type(ap, **format, op);
	return (ft_format_parse(ap, op));
}
