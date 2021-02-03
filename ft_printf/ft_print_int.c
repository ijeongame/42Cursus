/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 17:03:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_int(va_list ap, t_format *op)
{
	long long int	num;
	char			*value;
	int				cnt;
	int				len;

	num = ft_extend_di(ap, op);
	value = ft_lltoa(num);
	len = ft_strlen(value);
	cnt = ;
	return (cnt);
}
