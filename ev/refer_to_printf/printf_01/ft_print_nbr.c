/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:22:47 by inshin            #+#    #+#             */
/*   Updated: 2021/01/11 00:05:48 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_nbr_type(va_list ap, t_info *info)
{
	char	*value;

	value = NULL;
	if (info->type == 'i' || info->type == 'd')
		value = ft_itoa(va_arg(ap, int));
	else if (info->type == 'u')
		value = ft_lltoa(va_arg(ap, unsigned int));
	else if (info->type == 'x')
		value = ft_lltoa_base(va_arg(ap, unsigned int), HEXLOW);
	else if (info->type == 'X')
		value = ft_lltoa_base(va_arg(ap, unsigned int), HEXUPPPER);
	else if (info->type == 'p')
		value = ft_lltoa_base(va_arg(ap, unsigned long long), HEXLOW);
	return (value);
}

static char	*value_process(char *str, int len, int minus)
{
	int		str_len;
	char	*newstr;

	if (len == 0)
		return (ft_strdup(""));
	str_len = ft_strlen(str);
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstr[len] = '\0';
	ft_memset(newstr, '0', len);
	if (minus)
		newstr[0] = '-';
	ft_memcpy(newstr + len - (str_len - minus), str + minus, str_len - minus);
	return (newstr);
}

static int	pre_process(char **value, t_info *info)
{
	char	*tmp;
	int		len;
	int		is_minus;

	is_minus = 0;
	len = ft_strlen(*value);
	if (*value[0] == '0' && len == 1 && info->precision == 0)
		len = 0;
	if (*value[0] == '-')
		is_minus = 1;
	if (info->precision - (len - is_minus) > 0)
		len = info->precision + is_minus;
	if (info->precision < 0 && info->zero == 1 && info->width - len > 0)
		len = info->width;
	tmp = value_process(*value, len, is_minus);
	free(*value);
	*value = tmp;
	len = ft_strlen(*value);
	return (len);
}

static int	post_process(char *value, int len, t_info *info)
{
	char	*s;
	int		cnt;

	if (len > info->width)
		info->width = len;
	if (!(s = (char *)malloc(sizeof(char) * (info->width + 1))))
		return (ERROR);
	s[info->width] = '\0';
	info->zero == 1 && info->precision < 0 ?
		ft_memset(s, '0', info->width) : ft_memset(s, ' ', info->width);
	info->minus == 1 ? ft_memcpy(s, value, len) :
		ft_memcpy(s + info->width - len, value, len);
	cnt = ft_putstr(s);
	free(value);
	free(s);
	return (cnt);
}

int			print_nbr(va_list ap, t_info *info)
{
	int		len;
	char	*value;
	char	*tmp;

	value = check_nbr_type(ap, info);
	len = pre_process(&value, info);
	if (info->type == 'p')
	{
		tmp = ft_strjoin("0x", value);
		len += 2;
		free(value);
		value = tmp;
	}
	return (post_process(value, len, info));
}
