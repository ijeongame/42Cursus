/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/24 21:26:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt; //구조체에 넣어서 해결

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (!(ft_init_flist(ap, &format, cnt)))
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

int main(void)
{
	ft_printf("%-0# +10d",123123123123);
}