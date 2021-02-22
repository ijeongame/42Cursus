/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:05:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 01:53:47 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_store_res(char *n_str, int len, t_format *op)
{
//flag를 적용하지 않은 새로운 문자열을 만들어 반환한다.
	int		s_len;
	char	*res;

	s_len = ft_strlen(n_str);
	if (len == 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(res, '0', len);
	if (op->sign)
		res[0] = '-';
	ft_memcpy(res + len - (s_len - op->sign), n_str + op->sign, s_len - op->sign);
	res[len] = '\0';
	return (res);
}

static int	ft_calc_width(char *n_str, t_format *op)
{
	int		len;

	len = ft_strlen(n_str);
//우선적으로 precision의 조건에 따라 len를 구하고 새로운 문자열을 만들어 그 문자열의 길이를 반환한다.
//조건들로 정해진 길이로 새로운 문자열을 만든 후 flag에 따라 남은 문자열을 바꿔준다.
	if (op->prec < 0 && op->width > len && op->zero)
		len = op->width;
	if (op->prec == 0 && *n_str == '0')
		len = 0;
	if (op->prec > len - op->sign)
		len = op->prec + op->sign;
	return (len);
}

static int	ft_print_res(char *tmp, int len, t_format *op)
{
	char	*res;
	int		cnt;

	if (!(res = (char *)malloc(sizeof(char) * (op->width + 1))))
		return (-1);
	if (op->prec < 0 && op->zero && !op->left)
	{
		ft_memset(res, '0', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else if (!op->left)
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res, tmp, len);
	}
	cnt = ft_putstr(res);
	free(tmp);
	free(res);
	return (cnt);
}

int			ft_print_int(va_list ap, t_format *op)
{
	char	*n_str;
	char	*tmp;
	int		len;

	n_str = ft_itoa(va_arg(ap, int));
	if (*n_str == '-')
		op->sign = 1;
	len = ft_calc_width(n_str, op);
	tmp = ft_store_res(n_str, len, op);
	free(n_str);
	len = ft_strlen(tmp);
	if (len > op->width)
		op->width = len;
	return (ft_print_res(tmp, len, op));
}
