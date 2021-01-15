/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/15 18:03:12 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

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
	op->len = cnt;
	op->str = format;
	return (op);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (char *)str;
}

int			ft_parse_format(va_list ap, t_format *op)
{
	if (ft_strchr("-0# +", **format))
		ft_parse_flag(ap, format, op);
	if (ft_strchr("123456789*", **format))
		ft_parse_width(ap, format, op);
	// if (ft_strchr(".", **format))
	// 	ft_parse_prec(ap, op);
	if (ft_strchr("cspdiuxX%", **format))
		ft_parse_type(ap, **format, op);
	return (0);
}

int			ft_parse_start(va_list ap, const char **format, int cnt)
{
	t_format	*op;

	if (!(op = ft_set_list(format, cnt)))
		return (-1);
	return (ft_parse_format(ap, op));
}
