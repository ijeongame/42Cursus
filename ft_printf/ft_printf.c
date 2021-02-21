/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/21 18:33:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		start_printf(const char *format, va_list ap, t_list *op)
{
	int s_cnt;

	s_cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			s_cnt = ft_parse_start(ap, &format);
			if (s_cnt == -1)
				return (0);
			cnt += s_cnt;
		}
		else
		{
			cnt += write(1, format, 1);
			format++;
		}
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
