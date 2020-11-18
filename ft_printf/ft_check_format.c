/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:38:58 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/18 18:59:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//check format option
void		ft_check_format(va_list ap, char **format, t_format *option)
{
	//option_check
	while(**format && !format_type(format))
	{
		//flag
		if (**format == '-')
			option->flag.left = 1;
		else if (**format == '0')
			option->flag.zero = 1;
		else if (**format == ' ')
			option->flag.space = 1;
		else if (**format == '#')
			option->flag.base = 1;
		else if (**format == '+')
			option->flag.sign = 1;
		//width
		else if (**format >= '1' && **format <= '9' || **format =='*')
			option->width = ft_check_width(ap, **format);
		//precision
		else if (**format == '.')
			option->prec = ft_check_prec(**format);
		format++;
	}
}

//check width
int		ft_check_width(va_list ap, char **format)
{
	int width;

	if (ft_isdigit(**format))
		width = ft_atoi(**format);
	else if(**format == '*')
		width = va_arg(ap, int);
	return (width);
}

//format의 type과 flag에 따라 작동하는 함수 구현
int		format_type(char **format)
{
	if (**format == 'c')
		return (1);
	else if (**format == 's')
		return (1);
	else if (**format == 'p')
		return (1);
	else if (**format == 'd' || **format == 'i')
		return (1);
	else if (**format == 'u')
		return (1);
	else if (**format == 'x')
		return (1);
	else if (**format == 'X')
		return (1);
	else if (**format == '%')
		return (1);
	return (-1);
}

//set t_format option
static void	ft_set_option(t_format *option)
{
	option->flag.left = 0;
	option->flag.zero = 0;
	option->flag.space = 0;
	option->flag.base = 0;
	option->flag.sign = 0;
	option->width = 0;
	option->prec = -1;
	option->type = 0;
}
