/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/03/01 22:41:24 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct			s_format{
	int			left;
	int			zero;
	int			sign;
	int			width;
	int			prec;
	int			type;
}						t_format;

int						ft_printf(const char *format, ...);
void					ft_init_list(t_format *op);

int						ft_print_char(va_list ap, t_format *op);
int						ft_print_str(va_list ap, t_format *op);
int						ft_print_ptr(va_list ap, t_format *op);
int						ft_print_int(va_list ap, t_format *op);
int						ft_print_un_int(va_list ap, t_format *op);
int						ft_print_hex(va_list ap, t_format *op);
int						ft_print_per(t_format *op);

#endif
