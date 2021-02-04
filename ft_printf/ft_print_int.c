/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/04 16:34:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_apply_flag(long long int num, t_format *op)
{
	if (num)
}

static void	ft_apply_width(t_format *op)
{

}

static void	ft_apply_perc(t_format *op)
{

}

static void	ft_print_res(t_format *op, char *n_str, int t_len)
{
	if ()
}

int			ft_print_int(va_list ap, t_format *op)
{
	long long int	num;
	char			*n_str;
	int				len;
	int				t_len;

	num = ft_extend_di(num, op);
	n_str = ft_lltoa(num);
	//문자열을 입력 받은것을 strjoin을 통해 각 옵션을 적용한 문자열과 합친다.
	len = ft_strlen(n_str);
	//precision > width > len 순으로 우선순위를 가진다.
	if (op->width > len)
		t_len = op->width;
	else
		t_len = len;
	if (op->prec > t_len)
		t_len = op->prec;
	else
		t_len = t_len;
	if (num < 0 || op->sign || op->space)
		++t_len;
	ft_print_res(op, n_str, t_len);
	return (t_len);
}
