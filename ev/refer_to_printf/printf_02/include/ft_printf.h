/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmyungjin <jungmyungjin@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:16:44 by jungmyungjin      #+#    #+#             */
/*   Updated: 2021/01/10 23:14:25 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAG_DASH	1
# define FLAG_ZERO	2
# define FLAG_SPACE	4
# define FLAG_PLUS	8
# define FLAG_SHARP	16
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct	s_format
{
	int		flag;
	int		width;
	int		*precision;
	char	*size;
	char	type;
	void	*value;
	char	*value_sign;
	int		*value_is_neg;
}				t_format;
/*
** -------------------------- basic function ---------------------------------
*/
int				ft_strncmp(const char *s1, const char *s2, int len);
int				ft_strlen(const char *s1);
char			*ft_strdup(const char *s1);
int				ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_atoi(const char *nptr);
char			*ft_itoa(long long n);
int				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
/*
** -------------------------- common_func  -----------------------------
*/
void			free_string(char **s);
void			free_format(t_format **format);
/*
** -------------------------- util_foramt_checker  -------------------------
*/
t_format		*new_format(void);
/*
** -------------------------- format_checker  -------------------------
*/
int				check_flag(char *str, int *cnt);
int				check_width(char *str, int *cnt, va_list ap, t_format **format);
int				*check_precision(char *str, int *cnt, va_list ap);
char			*check_size(char *str, int *cnt);
char			check_type(char *str, int *cnt);
/*
** -------------------------- format_leader  ---------------------------
*/
char			*apply_sign(t_format **format, char *value);
void			apply_format_width(t_format **format, char **result);
void			common_precision(t_format **format, char **result);
void			get_percent_value(t_format **format, char **result);
void			get_string_value
(va_list ap, t_format **format, int *total_letter);
void			get_char_value
(va_list ap, t_format **format, int *total_letter);
void			get_pointer_value(va_list ap, t_format **format, char **result);
void			get_int_value(va_list ap, t_format **format, char **result);
void			get_uint_value(va_list ap, t_format **format, char **result);
int				get_value_by_type
(va_list ap, t_format **format, int *get_value_by_type);
/*
** -------------------------- main function ---------------------------------
*/
t_format		*format_checker(char *str, int *cnt, va_list ap);
int				ft_printf(const char *str, ...);
#endif
