/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:55:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/15 16:48:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_type(va_list ap, const char **format, t_format *op)
{
	if (**format == 'c')
		ft_print_char(ap, format);
	if (**format == 's')
		ft_print_str(ap, format);
	if (**format == 'p')
		ft_print_ptr(ap, format);
	if (**format == 'd' || **format == 'i')
		ft_print_int(ap, op, **format);
	if (**format == 'u')
		ft_print_un_int(ap, format, op);
	// if (**format == 'x' || **format == 'X')
	// 	ft_print_hex();
	// if (**format == '%')
	// 	ft_print_per();
	// if (**format == 'n')
	// if (**format == 'f' || **format == 'e' || **format == 'g')
	return (0);
}