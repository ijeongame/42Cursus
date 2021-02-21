/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:26:39 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 23:07:23 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	apply_format_width(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;

	empty_width = (*format)->width - ft_strlen(*result);
	if ((*format)->value_sign)
		empty_width -= 1;
	add_str = NULL;
	if ((*format)->flag & FLAG_ZERO && !(*format)->precision)
		while (empty_width-- > 0)
			add_str = ft_strjoin(add_str, ft_strdup("0"));
	else
		while (empty_width-- > 0)
			add_str = ft_strjoin(add_str, ft_strdup(" "));
	if ((*format)->flag & FLAG_ZERO && !(*format)->precision)
		*result = ft_strjoin(add_str, *result);
	else if ((*format)->flag & FLAG_DASH)
		*result = ft_strjoin(*result, add_str);
	*result = ft_strjoin(ft_strdup((*format)->value_sign), *result);
	if (!(((*format)->flag & FLAG_ZERO && !(*format)->precision) ||
	(*format)->flag & FLAG_DASH))
		*result = ft_strjoin(add_str, *result);
}

char	*apply_sign(t_format **format, char *value)
{
	char *result;

	result = NULL;
	if ((*format)->flag & FLAG_PLUS)
	{
		if (*((*format)->value_is_neg) == 0)
			(*format)->value_sign = ft_strdup("+");
	}
	if ((*format)->flag & FLAG_SPACE)
	{
		if (*((*format)->value_is_neg) == 0)
			(*format)->value_sign = ft_strdup(" ");
	}
	if (*((*format)->value_is_neg) == 1)
	{
		(*format)->value_sign = ft_strdup("-");
		result = ft_substr(value, 1, ft_strlen(value) - 1);
	}
	else if (*((*format)->value_is_neg) == 0)
		result = ft_strdup(value);
	free_string(&value);
	value = NULL;
	return (result);
}

void	common_precision(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;
	int		len_value;

	if (*(*format)->precision < 0)
	{
		free((*format)->precision);
		(*format)->precision = NULL;
		return ;
	}
	if (*(*format)->precision == 0 && *(int*)(*format)->value == 0)
	{
		free(*result);
		free((*format)->value);
		*result = NULL;
		(*format)->value = NULL;
	}
	len_value = ft_strlen(*result);
	if (!(*format)->precision || (((*format)->precision - len_value) <= 0))
		return ;
	add_str = NULL;
	empty_width = *((*format)->precision) - len_value;
	while (empty_width-- > 0)
		add_str = ft_strjoin(add_str, ft_strdup("0"));
	*result = ft_strjoin(add_str, *result);
}
