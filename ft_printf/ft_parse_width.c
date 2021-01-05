/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:14 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/18 18:47:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_width(va_list ap, const char **format, t_format *op)
{
	int	s_width;

	s_width = 0;
	if (**format == '*')
	{
		if ((s_width = va_arg(ap, int)) < 0)
		{
			s_width = -s_width;
			**(format)++;
		}
	}
	else
	{
		if (ft_isdigit(**format))
		{
			s_width *= 10;
			s_width += **format - '0';
			**(format)++;
		}
	}
	op->width = s_width;
	return (0);
}
