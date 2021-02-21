/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/21 21:01:30 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_parse_type(char format, va_list ap, t_format *op)
{
	if (format == 'c')
		return (ft_print_char(ap, op));
	if (format == 's')
		return (ft_print_str(ap, op));
	if (format == 'p')
		return (ft_print_ptr(ap, op));
	if (format == 'd' || format == 'i')
		return (ft_print_int(ap, op));
	if (format == 'u')
		return (ft_print_un_int(ap, op));
	if (format == 'x' || format == 'X')
		return (ft_print_hex(ap, op));
	if (format == '%')
		return (ft_print_per(op));
	return (0);
}

static void		ft_parse_format(char format, va_list ap, t_format *op)
{
	//flag
	if (format == '0' && op->zero == 0 && op->point == 0 && op->width == 0)
		op->zero = 1;
	else if (format == '-')
		op->left = 1;
	//wdith & precision
	else if (format == '.')
	{
		op->point = 1;
		op->prec = 0;
	}
	else if (format == '*')
	{
		if (op->point == 0)
		{
			if ((op->width = va_arg(ap, int)) < 0)
			{
				op->width *= -1;
				op->left = 1;
			}
		}
		else
			op->prec = va_arg(ap, int);
	}
	else if (ft_isdigit(format))
	{
		if (op->point == 0)
			op->width = (op->width * 10) + format - '0';
		else
			op->prec = (op->prec * 10) + format - '0';
	}
}

static int		start_printf(const char *format, va_list ap, t_format *op)
{
	int s_cnt;

	s_cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format && ft_strchr("cspdiuxX%", *format) == 0)
				ft_parse_format(*(format++), ap, op);
			if (*format && ft_strchr("cspdiuxX%", *format) != 0)
				s_cnt += ft_parse_type(*(format++), ap, op);
		}
		else
			s_cnt += ft_putchar(*(format++));
	}
	return (s_cnt);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*op;
	int			cnt;

	va_start(ap, format);
	if (!(op = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	ft_init_list(op);
	cnt = start_printf(format, ap, op);
	va_end(ap);
	return (cnt);
}
