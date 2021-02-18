/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:50:54 by inshin            #+#    #+#             */
/*   Updated: 2021/01/08 17:14:19 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier(va_list ap, char type, t_info *info)
{
	if (type == '%')
		return (print_percent(info));
	else if (type == 'c')
		return (print_char(ap, info));
	else if (type == 's')
		return (print_str(ap, info));
	else if (type == 'i' || type == 'd' || type == 'u')
		return (print_nbr(ap, info));
	else if (type == 'x' || type == 'X' || type == 'p')
		return (print_nbr(ap, info));
	else
		return (ERROR);
}

static void	check_option(va_list ap, char fmt, t_info *info)
{
	if (fmt == '0' && info->zero == 0 && info->dot == 0 && info->width == 0)
		info->zero = 1;
	else if (fmt == '-')
		info->minus = 1;
	else if (fmt == '.')
	{
		info->dot = 1;
		info->precision = 0;
	}
	else if (fmt == '*')
	{
		if (info->dot == 0)
			info->width = va_arg(ap, int);
		else
			info->precision = va_arg(ap, int);
	}
	else if (ft_isdigit(fmt))
	{
		if (info->dot == 0)
			info->width = (info->width * 10) + fmt - '0';
		else
			info->precision = (info->precision * 10) + fmt - '0';
	}
}

static int	run_printf(const char *fmt, va_list ap, t_info *info)
{
	int cnt;

	cnt = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			while (*fmt && ft_strchr(TYPE, *fmt) == 0)
				check_option(ap, *(fmt++), info);
			pre_star(info);
			info->type = *fmt;
			if (*fmt && ft_strchr(TYPE, *fmt) != 0)
				cnt += check_specifier(ap, *(fmt++), info);
			init_info(info);
		}
		else
			cnt += ft_putchar(*(fmt++));
	}
	return (cnt);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_info	*info;
	int		cnt;

	va_start(ap, fmt);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (ERROR);
	init_info(info);
	cnt = run_printf(fmt, ap, info);
	va_end(ap);
	return (cnt);
}
