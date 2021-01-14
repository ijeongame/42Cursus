/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/14 21:41:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

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

int			ft_parse_format(va_list ap, const char **format, t_format *op)
{
	if (ft_strchr("-0# +", **format))
		ft_parse_flag(ap, format, op);
	if (ft_strchr("123456789*", **format))
	{
		printf("%c\n", **format);
		ft_parse_width(ap, format, op);
	}
	else
	{
		printf("%d%d%d%d%d%d\n",op->left, op->zero, op->base, op->space, op->sign, op->width);
		printf("%c\n",**format);
	}
	// if (ft_strchr(".", **format))
	// 	ft_parse_prec(ap, op);
	// if (ft_strchr("cspdiuxXnfgeo%", **format))
	// 	ft_parse_type(ap, **format, op);
	return (0);
}
