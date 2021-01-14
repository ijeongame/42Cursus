/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:37:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/14 20:49:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static void	*ft_init_flist(t_format *op)
{
	op->left = 0;
	op->zero = 0;
	op->base = 0;
	op->space = 0;
	op->sign = 0;
	op->width = 0;
	op->prec = 0;
	op->type = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt; //구조체에 넣어서 해결
	t_format	*op;

	if (!(op = malloc(sizeof(t_format))))
		return (0);
	ft_init_flist(op);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			printf("%s\n",format);
			//if (format = "abcdefg%-10d")
			//*format start '-'
			//함수인자로 format을 넘겨주면 '-'만 넘어간다.
			//'-'이후의 문자열을 전부 넘겨주기 위해서  format의 주소를 넘겨준다.
			//ft_parse_format 함수에서 이중포인터로 받음.
			if (!(ft_parse_format(ap, &format, op)))
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