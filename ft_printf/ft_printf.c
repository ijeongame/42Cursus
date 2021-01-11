/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/11 20:40:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!(ft_parse_format(ap, *format)))
				return (-1);
		}
		else
		{
			cnt += write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (cnt);
}
