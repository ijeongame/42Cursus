/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/21 21:51:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_store_res(char *n_str, int len, int sign)
{

}

static int	ft_calc_width(char **n_str, t_format *op)
{
	char	*tmp;
	int		len;
	int		sign;

	sign = 0;
	len = ft_strlen(*n_str);
	if (*n_str[0] == '0' && len == 1 & op->prec == 0)
		len = 0;
	if (*n_str[0] == '-')
		sign = 1;
	if (op->prec - (len - sign) > 0)
		len = op->prec + sign;
	if (op->prec < 0 && op->zero && op->width - len > 0)
		len = op->width;
}

int			ft_print_int(va_list ap, t_format *op)
{
	char			*n_str;
	int				len;

	n_str = ft_itoa(va_arg(ap, int));
	len = ft_calc_width(&n_str, op);

	return (len);
}
