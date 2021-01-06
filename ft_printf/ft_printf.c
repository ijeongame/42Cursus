/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/06 22:26:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

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
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}

int main(void)
{
	ft_printf("1234567%d\n");
}
