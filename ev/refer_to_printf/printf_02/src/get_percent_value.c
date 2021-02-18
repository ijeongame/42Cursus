/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:25 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:20:59 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	apply_percent_width(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;

	empty_width = (*format)->width - ft_strlen(*result);
	if ((*format)->value_sign)
		empty_width -= 1;
	add_str = NULL;
	if ((*format)->flag & FLAG_ZERO)
		while (empty_width-- > 0)
			add_str = ft_strjoin(add_str, ft_strdup("0"));
	else
		while (empty_width-- > 0)
			add_str = ft_strjoin(add_str, ft_strdup(" "));
	if ((*format)->flag & FLAG_ZERO)
		*result = ft_strjoin(add_str, *result);
	else if ((*format)->flag & FLAG_DASH)
		*result = ft_strjoin(*result, add_str);
	if (!((*format)->flag & FLAG_ZERO || (*format)->flag & FLAG_DASH))
		*result = ft_strjoin(add_str, *result);
}

void	get_percent_value(t_format **format, char **result)
{
	(*format)->value = ft_strdup("%");
	if ((*format)->flag & FLAG_ZERO && (*format)->flag & FLAG_DASH)
		(*format)->flag -= FLAG_ZERO;
	*result = ft_strdup("%");
	apply_percent_width(format, result);
}
