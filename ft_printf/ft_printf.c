/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/25 21:10:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//step1 - 간단한 %d출력.

int		ft_printf(const char *format, ...)
{
	va_list 	ap; //argument point
	//t_format 	*option;
	int			cnt_ch;	//num of all character

	//ap를 시작지점으로 둔다. stack piont와 같은 역할. 여러 인수를 저장하는데 쓰일 타입을 선언.
	//ft_set_option(option);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			// ft_check_format(ap, &format, option);
			ft_print_int(ap, &format);
		}
		else
			write(1, format++, 1);
	}
	va_end(ap);
	return (cnt_ch);
}

void	ft_print_int(va_list ap, const char **format)
{
	char *res;

	while (*format)
	{
		if (**format == '-')
		{
			res = 
		}
		if (**format == 'd')
		{
			res = ft_itoa(va_arg(ap, int *));
			write(1, res, ft_strlen(res));
		}
		format++;
	}
}

int		main(void)
{
	ft_printf("%d",42);
}
