/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwon <kwon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:11:04 by kwon              #+#    #+#             */
/*   Updated: 2020/10/17 03:26:20 by kwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

//문자열 함수와 문자 판별 함수를 사용하기 위해 써줘야 하는게 아닌가?
// #include    <string.h>
// #include    <ctype.h>

void	*ft_memset(void *ptr, int value, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memchr(const void *ptr, int value, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
void	*ft_calloc(size_t nelem, size_t size);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strcjr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t size);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);

int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(char c);
int		ft_isprint(char c);
int		ft_toupper(char c);
int		ft_tolower(char c);

#endif
