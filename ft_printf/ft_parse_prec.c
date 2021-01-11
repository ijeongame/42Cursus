/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:55:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/11 21:38:48 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_prec(va_list ap, t_format *op)
{
	int		tmp;

	tmp = 0;
	++(op->fmat);
	if (*(op->fmat) == '*')
	{
		if ((op->prec = va_arg(ap, int)) < 0)
			++(op->fmat);
	}
	else
	{
		while (ft_isdigit(*(op->fmat)))
		{
			tmp *= 10;
			tmp += op->fmat - '0';
			++(op->fmat);
		}
		op->prec = tmp;
	}
	return (ft_parse_format(ap, op));
}
