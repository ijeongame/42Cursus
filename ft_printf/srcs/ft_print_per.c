/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:22:35 by hkwon             #+#    #+#             */
/*   Updated: 2021/03/02 23:12:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_per(t_format *op)
{
	int	cnt;
	int	s_width;

	cnt = 0;
	s_width = op->width - 1;
	if (op->left)
	{
		cnt += ft_putchar('%');
		while (s_width-- > 0)
			cnt += ft_putchar(' ');
	}
	else
	{
		while (s_width-- > 0)
		{
			if (op->zero)
				cnt += ft_putchar('0');
			else
				cnt += ft_putchar(' ');
		}
		cnt += ft_putchar('%');
	}
	return (cnt);
}
