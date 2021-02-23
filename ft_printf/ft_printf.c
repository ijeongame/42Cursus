/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 20:34:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_parse_type(char format, va_list ap, t_format *op)
{
	op->type = format;
	if (format == 'c')
		return (ft_print_char(ap, op));
	// if (format == 's')
	// 	return (ft_print_str(ap, op));
	// if (format == 'p')
	// 	return (ft_print_ptr(ap, op));
	if (format == 'd' || format == 'i')
		return (ft_print_int(ap, op));
	if (format == 'u')
		return (ft_print_un_int(ap, op));
	// if (format == 'x' || format == 'X')
	//  	return (ft_print_hex(ap, op));
	// if (format == '%')
	// 	return (ft_print_per(op));
	return (0);
}

static void		ft_parse_width_prec(char format, va_list ap, t_format *op)
{
	if (ft_isdigit(format))
	{
		if (op->prec == -1)
			op->width = (op->width * 10) + format - '0';
		else
			op->prec = (op->prec * 10) + format - '0';
	}
	else if (format == '*')
	{
		if (op->prec == -1)
		{
			if ((op->width = va_arg(ap, int)) < 0)
			{
				op->width *= -1;
				op->left = 1;
			}
		}
		else
		{
			if ((op->prec = va_arg(ap, int)) < 0)
				op->prec = -1;
		}
	}
}

static void		ft_parse_format(char format, va_list ap, t_format *op)
{
	if (format == '0' && op->prec == -1 && op->width == 0)
		op->zero = 1;
	else if (format == '-')
		op->left = 1;
	else if (format == '.')
		op->prec = 0;
	else if (ft_isdigit(format) || format == '*')
		ft_parse_width_prec(format, ap, op);
}

static int		start_printf(const char *format, va_list ap)
{
	int			s_cnt;
	t_format	*op;

	s_cnt = 0;
	if (!(op = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_init_list(op);
			while (*format && !ft_strchr("cspdiuxX%", *format))
				ft_parse_format(*(format++), ap, op);
			if (op->left == 1 || op->prec > -1)
				op->zero = 0;
			s_cnt += ft_parse_type(*(format++), ap, op);
		}
		else
			s_cnt += ft_putchar(*(format++));
	}
	free(op);
	return (s_cnt);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt;

	va_start(ap, format);
	cnt = start_printf(format, ap);
	va_end(ap);
	return (cnt);
}

int		main(void)
{
	ft_printf("%03d%d끝\n", 1234,5678);
	ft_printf("%010d끝\n", 1234);
	ft_printf("%-10d끝\n", -1234);
	ft_printf("%-010d끝\n", -1234);
	ft_printf("%.10d끝\n", 1234);
	ft_printf("%.10d끝\n", -1234);
	ft_printf("%8.7d끝\n", 123456);

	ft_printf("%u\n", -1);
	ft_printf("%010u\n", 12);
	ft_printf("%-10u\n", 11);
	// ft_printf("%10c끝\n",'a');
	// ft_printf("%-10c끝\n", 'a');
	// ft_printf("%010c끝\n", 'a');
}