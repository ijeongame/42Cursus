/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:26:17 by inshin            #+#    #+#             */
/*   Updated: 2021/01/08 03:37:08 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_percent(t_info *info)
{
	int cnt;
	int w;

	cnt = 0;
	w = info->width - 1;
	if (info->minus == 0)
		while (w-- > 0)
		{
			if (info->zero == 1)
				cnt += ft_putchar('0');
			else
				cnt += ft_putchar(' ');
		}
	cnt += ft_putchar('%');
	if (info->minus == 1)
		while (w-- > 0)
			cnt += ft_putchar(' ');
	return (cnt);
}

int			print_char(va_list ap, t_info *info)
{
	int cnt;
	int w;

	cnt = 0;
	w = info->width - 1;
	if (info->minus == 0)
		while (w-- > 0)
			cnt += ft_putchar(' ');
	cnt += ft_putchar(va_arg(ap, int));
	if (info->minus == 1)
		while (w-- > 0)
			cnt += ft_putchar(' ');
	return (cnt);
}

static int	pre_process_width(int *len, t_info *info)
{
	int w;

	w = info->width;
	if (*len > info->precision && info->precision >= 0)
		*len = info->precision;
	if (*len > w)
		w = *len;
	return (w);
}

int			print_str(va_list ap, t_info *info)
{
	int		cnt;
	char	*value;
	char	*s;
	int		len;
	int		w;

	cnt = 0;
	value = va_arg(ap, char *);
	if (value == NULL)
		value = "(null)";
	len = ft_strlen(value);
	w = pre_process_width(&len, info);
	if (!(s = (char *)malloc(sizeof(char) * (w + 1))))
		return (ERROR);
	s[w] = '\0';
	if (info->zero == 1 && info->precision == -1 && info->minus == 0)
		ft_memset(s, '0', w);
	else
		ft_memset(s, ' ', w);
	info->minus == 1 ? ft_memcpy(s, value, len)
					: ft_memcpy(s + w - len, value, len);
	cnt += ft_putstr(s);
	free(s);
	return (cnt);
}
