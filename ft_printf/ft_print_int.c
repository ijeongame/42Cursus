/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 22:41:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_int(va_list ap, t_format *op)
{
	long long int	num;
	char			*n_str;
	int				cnt;
	int				len;

	num = ft_extend_di(num, op);
	n_str = ft_lltoa(num);

	return (cnt);
}
