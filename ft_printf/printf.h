/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/14 20:55:31 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft.h"

typedef struct	s_format{
	int			left;
	int			sign;
	int			space;
	int			base;
	int			zero;
	int			width;
	int			prec;
	int			type;
	int			len;
}				t_format;

int				ft_printf(const char *format, ...);

int				ft_parse_format(va_list ap, const char **format, t_format *op);
int				ft_parse_flag(va_list ap, const char **format, t_format *op);
int				ft_parse_width(va_list ap, const char **format, t_format *op);
int				ft_parse_prec(va_list ap, t_format *op);
int				ft_parse_type(va_list ap, const char **format, t_format *op);

int				ft_print_char(va_list ap, t_format *op);

#endif
