/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/04 16:46:34 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt;
	int			s_cnt;

	cnt = 0;
	va_start(ap, format);
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
	va_end(ap);
	return (cnt);
}
