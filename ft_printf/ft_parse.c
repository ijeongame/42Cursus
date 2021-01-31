/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/31 15:49:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_flag(va_list ap, t_format *op)
{
	if (op->str == '-')
		op->left = 1;
	if (op->str == '0')
		op->zero = 1;
	if (op->str == '#')
		op->base = 1;
	if (op->str == ' ')
		op->space = 1;
	if (op->str == '+')
		op->sign = 1;
	++(op->str);
	return (ft_parse_format(ap, op));
}

int	ft_parse_width(va_list ap, t_format *op)
{
	int		s_width;

	s_width = 0;
	if (op->str == '*')
	{
		if ((s_width = va_arg(ap, int)) < 0)
			s_width = -s_width;
		++(op->str);
	}
	else
	{
		while (ft_isdigit(op->str))
		{
			s_width *= 10;
			s_width += (op->str) - '0';
			++(op->str);
		}
	}
	op->width = s_width;
	return (ft_parse_format(ap, op));
}

int	ft_parse_prec(va_list ap, t_format *op)
{
	int		tmp;

	tmp = 0;
	++(op->str);
	if (op->str == '*')
	{
		if ((op->prec = va_arg(ap, int)) < 0)
			++(op->str);
	}
	else
	{
		while (ft_isdigit(*(op->fmat)))
		{
			tmp *= 10;
			tmp += op->fmat - '0';
			++(op->fmat);
		}
		op->prec = tmp;
	}
	return (ft_parse_format(ap, op));
}

int	ft_parse_type(va_list ap, const char **format, t_format *op)
{
	if (**format == 'c')
		ft_print_char(ap, format);
	if (**format == 's')
		ft_print_str(ap, format);
	if (**format == 'p')
		ft_print_ptr(ap, format);
	if (**format == 'd' || **format == 'i')
		ft_print_int(ap, op, **format);
	if (**format == 'u')
		ft_print_un_int(ap, format, op);
	// if (**format == 'x' || **format == 'X')
	// 	ft_print_hex();
	// if (**format == '%')
	// 	ft_print_per();
	// if (**format == 'n')
	// if (**format == 'f' || **format == 'e' || **format == 'g')
	return (0);
}