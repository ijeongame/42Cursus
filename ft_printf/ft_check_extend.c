/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:44:59 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/04 16:46:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_extend_di(va_list ap, t_format *op)
{
	if (op->len_h == 1)
		return (short int)(va_arg(ap, int));
	if (op->len_h >= 2)
		return (signed char)(va_arg(ap, int));
	if (op->len_l == 1)
		return (va_arg(ap, long int));
	if (op->len_l >= 2)
		return (va_arg(ap, long long int));
	return (va_arg(ap, int));
}

unsigned long long int	ft_extend_u(va_list ap, t_format *op)
{
	if (op->len_h == 1)
		return (unsigned short int)(va_arg(ap, unsigned int));
	if (op->len_h >= 2)
		return (unsigned char)(va_arg(ap, unsigned int));
	if (op->len_l == 1)
		return (va_arg(ap, unsigned long int));
	if (op->len_l >= 2)
		return (va_arg(ap, unsigned long long int));
	return (va_arg(ap, unsigned int));
}
