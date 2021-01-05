/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/26 16:24:29 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_flag{
	int			left;
	int			sign;
	int			space;
	int			base;
	int			zero;
}				t_flag;

//2. create format list
typedef struct	s_format{
	t_flag		flag;
	int			width;
	int			prec;
	int			type;
	int			len;
	char		**fmat;
}				t_format;

t_format		*ft_init_flist(const char **format);
int				ft_printf(const char *format, ...);
int				ft_parse_format(va_list ap, const char **format);
int				ft_parse_flag(const char **format, t_format *op);
int				ft_parse_width(va_list ap, const char **format, t_format *op);
int				ft_parse_prec(va_list ap, t_format *op);
int				ft_parse_type(va_list ap, const char **format, t_format *op);

int				ft_print_char(va_list ap, t_format *op);

#endif
