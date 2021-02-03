/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/03 16:55:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft.h"

typedef struct			s_format{
	int			left;
	int			sign;
	int			space;
	int			base;
	int			zero;
	int			width;
	int			prec;
	int			len_h;
	int			len_l;
	int			type;
	char		**str;
}						t_format;

int						ft_printf(const char *format, ...);

int						ft_parse_start(va_list ap, const char **format, int cnt);
int						ft_parse_format(va_list ap, t_format *op);
int						ft_parse_width(va_list ap, t_format *op);
int						ft_parse_prec(va_list ap, t_format *op);
int						ft_parse_type(va_list ap, t_format *op);
int						ft_parse_extend(va_list ap, t_format *op);

int						ft_print_int(va_list ap, t_format *op);
int						ft_print_char(va_list ap, t_format *op);

long long int			ft_extend_di(va_list ap, t_format *op);
unsigned long long int	ft_extend_u(va_list ap, t_format *op);
char					*ft_lltoa(long long n);

#endif
