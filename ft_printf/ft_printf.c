/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/03 20:39:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			write(1, format, 1);
			//if(//write option)
			//create function
		}
		else
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	return (cnt);
}

int main(void)
{
	ft_printf("1234567%d\n");
}