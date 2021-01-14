/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/12 18:47:45 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_flag(va_list ap, const char **format, t_format *op)
{
	if (**format == '-')
		op->left = 1;
	if (**format == '0')
		op->zero = 1;
	if (**format == '#')
		op->base = 1;
	if (**format == ' ')
		op->space = 1;
	if (**format == '+')
		op->sign = 1;
	++(*format);
	return (ft_parse_format(ap, format, op));
}
