/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/26 16:18:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_flag(t_format *op)
{
	if (op->flag.sign)
		write(1, '+', 1);
	else if (op->flag.space)
		write(1, ' ', 1);
}

static int	ft_print_width(t_format *op)
{

}

static int	ft_print_prec(t_format *op)
{

}

int			ft_print_int(va_list ap, t_format *op, const char **format)
{
	long long int	num;
	char			*num_str;
	int				n_len;
	int				cnt;

	num = va_arg(ap, long long);
	num_str = ft_new_itoa(num);
	n_len = ft_strlen(num_str);
	if (n_len > op->width)
		cnt = n_len;
	else
		cnt = op->width;
}
