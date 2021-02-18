/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:26:44 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:56:08 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_flag(char *str, int *cnt)
{
	int flag_num;

	flag_num = 0;
	while (str[*cnt] == '-' || str[*cnt] == '0' || str[*cnt] == ' ' ||
	str[*cnt] == '+' || str[*cnt] == '#')
	{
		if (str[*cnt] == '-' && !(flag_num & FLAG_DASH))
			flag_num += FLAG_DASH;
		else if (str[*cnt] == '0' && !(flag_num & FLAG_ZERO))
			flag_num += FLAG_ZERO;
		else if (str[*cnt] == ' ' && !(flag_num & FLAG_SPACE))
			flag_num += FLAG_SPACE;
		else if (str[*cnt] == '+' && !(flag_num & FLAG_PLUS))
			flag_num += FLAG_PLUS;
		else if (str[*cnt] == '#' && !(flag_num & FLAG_SHARP))
			flag_num += FLAG_SHARP;
		(*cnt)++;
	}
	return (flag_num);
}

int		check_width(char *str, int *cnt, va_list ap, t_format **format)
{
	int width;

	width = 0;
	if (str[*cnt] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0 && !((*format)->flag & FLAG_DASH))
		{
			if (((*format)->flag & FLAG_ZERO))
				(*format)->flag -= FLAG_ZERO;
			(*format)->flag += FLAG_DASH;
		}
		if (width < 0)
			width *= -1;
		(*cnt)++;
	}
	else
	{
		width = ft_atoi(&str[*cnt]);
		while ('0' <= str[*cnt] && str[*cnt] <= '9')
			(*cnt)++;
	}
	return (width);
}

int		*check_precision(char *str, int *cnt, va_list ap)
{
	int *p_precision;
	int precision;

	p_precision = NULL;
	precision = 0;
	if (str[*cnt] == '.')
	{
		(*cnt)++;
		p_precision = (int*)malloc(sizeof(int));
		if ('0' <= str[*cnt] && str[*cnt] <= '9')
		{
			while ('0' <= str[(*cnt)] && str[(*cnt)] <= '9')
				precision = (precision * 10) + (str[(*cnt)++] - '0');
			*p_precision = precision;
		}
		else if (str[*cnt] == '*')
		{
			precision = va_arg(ap, int);
			*p_precision = precision;
			(*cnt)++;
		}
		else
			*p_precision = 0;
	}
	return (p_precision);
}

char	*check_size(char *str, int *cnt)
{
	char	*size;
	int		size_char;

	size = NULL;
	size_char = 0;
	if (str[*cnt] == 'h' || str[*cnt] == 'l')
	{
		size_char++;
		if (str[(*cnt) + 1] == str[*cnt])
			size_char++;
	}
	else if (str[*cnt] == 'j' || str[*cnt] == 'z' ||
	str[*cnt] == 't' || str[*cnt] == 'L')
		size_char++;
	size = (char*)malloc(sizeof(char) * (size_char + 1));
	ft_strlcat(size, &str[*cnt], size_char + 1);
	*cnt += size_char;
	return (size);
}

char	check_type(char *str, int *cnt)
{
	char type;

	type = '\0';
	if (str[*cnt] == 'c' || str[*cnt] == 'd' || str[*cnt] == 'i'
	|| str[*cnt] == 'e' || str[*cnt] == 'E' || str[*cnt] == 'f'
	|| str[*cnt] == 'g' || str[*cnt] == 'G' || str[*cnt] == 'a'
	|| str[*cnt] == 'A' || str[*cnt] == 's' || str[*cnt] == 'u'
	|| str[*cnt] == 'x' || str[*cnt] == 'X' || str[*cnt] == 'p'
	|| str[*cnt] == 'n' || str[*cnt] == '%')
	{
		type = str[*cnt];
	}
	(*cnt)++;
	return (type);
}
