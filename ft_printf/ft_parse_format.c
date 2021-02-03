/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 16:22:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_flag(va_list ap, t_format *op)
{
	if (**op->str == '-')
		op->left = 1;
	if (**op->str == '0')
		op->zero = 1;
	if (**op->str == '#')
		op->base = 1;
	if (**op->str == ' ')
		op->space = 1;
	if (**op->str == '+')
		op->sign = 1;
	++(*op->str);
	return (ft_parse_format(ap, op));
}

int		ft_parse_width(va_list ap, t_format *op)
{
	int		s_width;

	s_width = 0;
	if (**op->str == '*')
	{
		if ((s_width = va_arg(ap, int)) < 0)
			s_width = -s_width;
		++(*op->str);
	}
	else
	{
		while (ft_isdigit(**op->str))
		{
			s_width *= 10;
			s_width += **op->str - '0';
			++(*op->str);
		}
	}
	op->width = s_width;
	return (ft_parse_format(ap, op));
}

int		ft_parse_prec(va_list ap, t_format *op)
{
	int		s_prec;

	s_prec = 0;
	++(*op->str);
	if (**op->str == '*')
	{
		if ((op->prec = va_arg(ap, int)) < 0)
			++(*op->str);
	}
	else
	{
		while (ft_isdigit(**op->str))
		{
			s_prec *= 10;
			s_prec += **op->str - '0';
			++(*op->str);
		}
		op->prec = s_prec;
	}
	return (ft_parse_format(ap, op));
}

int		ft_parse_extend(va_list ap, t_format *op)
{
	if (**op->str == 'h')
		op->len_h += 1;
	if (**op->str == 'l')
		op->len_l += 1;
	++(*op->str);
	return (ft_parse_check(ap, op));
}

int		ft_parse_type(va_list ap, t_format *op)
{
	if (**op->str == 'c')
		ft_print_char(ap, op);
	if (**op->str == 's')
		ft_print_str(ap, op);
	if (**op->str == 'p')
		ft_print_ptr(ap, op);
	if (**op->str == 'd' || **op->str == 'i')
		ft_print_int(ap, op);
	if (**op->str == 'u')
		ft_print_un_int(ap, op);
	if (**op->str == '%')
		ft_print_per(ap, op);
	return (0);
}