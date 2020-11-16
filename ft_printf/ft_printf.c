/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/16 21:27:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


//step1 - 간단한 %d출력 - itoa 활용.

int		ft_printf(const char *format, ...)
{
	va_list ap; //argument point
	int		cnt_ch;	//num of all character
	int		cnt_type;//num of format character
	//ap를 시작지점으로 둔다. stack piont와 같은 역할. 여러 인수를 저장하는데 쓰일 타입을 선언.
	//format : %10000d 와 같은 형태.
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_option(ap, *format);
		}
		else
		{
			write(1, *format++, 1);
			cnt_ch++;
		}
	}
	va_end(ap);
	return (cnt_ch);
}

//check format option
int		ft_check_option(va_list ap, char **format)
{
	t_format	*option;

	//option_check
	while(**format && !format_type(*format))
	{
		if (*format == '-')
			option->flag.minus = 1;

		else if (**format >= '0' && **format <= '9' || **format =='*')
			option->width = ft_check_width(**format);
		else if (**format == '.')
			option->prec = ft_check_prec(**format);
		format++;
	}
}

//check format_width
int		ft_check_width(char **format)
{

}

//format의 type과 flag에 따라 작동하는 함수 구현
int		format_type(char **format)
{
	if (*format == 'c')
		return (1);
	else if (*format == 's')
		return (1);
	else if (*format == 'p')
		return (1);
	else if (*format == 'd' || *format == 'i')
		return (1);
	else if (*format == 'u')
		return (1);
	else if (*format == 'x')
		return (1);
	else if (*format == 'X')
		return (1);
	else if (*format == '%')
		return (1);
	return (-1);
}

//return value is num of characters
int		ft_putchar_out_d(va_list ap, char **format)
{
	int cnt;

	cnt = 0;
	while(**format)
	{
		wrtie(1,va_arg(ap, int), 1);
		*format++;
		cnt++;
	}
	return (cnt);
}

