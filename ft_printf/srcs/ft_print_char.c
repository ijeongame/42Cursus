/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:26:34 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/22 01:24:12 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap, t_format *op)
{
	int cnt;
	int s_width;

	cnt = 0;
	s_width = op->width - 1;
	if (op->left == 1)
	{
		cnt += ft_putchar(va_arg(ap, int));
		while (s_width-- > 0)
			cnt += ft_putchar(' ');
	}
	else
	{
		while (s_width-- > 0)
			cnt += ft_putchar(' ');
		cnt += ft_putchar(va_arg(ap, int));
	}
	return (cnt);
}
