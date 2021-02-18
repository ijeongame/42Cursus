/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:26:42 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	free_string(char **s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

void	free_format(t_format **format)
{
	if (*format == NULL)
		return ;
	if ((*format)->precision)
	{
		free((*format)->precision);
		(*format)->precision = NULL;
	}
	if ((*format)->size)
		free_string(&(*format)->size);
	if ((*format)->value)
	{
		free((*format)->value);
		(*format)->value = NULL;
	}
	if ((*format)->value_sign)
		free_string(&(*format)->value_sign);
	if ((*format)->value_is_neg)
	{
		free((*format)->value_is_neg);
		(*format)->value_is_neg = NULL;
	}
	free(*format);
	*format = NULL;
}
