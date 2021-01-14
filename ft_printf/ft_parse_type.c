/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:55:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/14 22:05:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_type(va_list ap, const char **format, t_format *op)
{
	if (**format == 'c')
		ft_print_c(ap, format);
	if (**format == 's')
		ft_print_s(ap, format);
	if (**format == 'p')
		ft_print_p(ap, format);
	if (**format == 'd' || **format == 'i')
		ft_print_di(ap, op, **format);

	if (**format == 'u')
	if (**format == 'x' || **format == 'X')
	if (**format == '%')

	if (**format == 'o')
	if (**format == 'n')
	if (**format == 'f' || **format == 'e' || **format == 'g')
	
}