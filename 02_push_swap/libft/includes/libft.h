/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:11:04 by kwon              #+#    #+#             */
/*   Updated: 2021/06/01 05:12:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct	s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

void			*ft_memset(void *ptr, int value, size_t size);
void			ft_bzero(void *ptr, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memchr(const void *ptr, int value, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t size);
void			*ft_calloc(size_t nelem, size_t size);

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *big, const char *little, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
char			*ft_strdup(const char *src);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_count(int n);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_lltoa(long long n);
char			*ft_convert_base(unsigned long long n, char *convert);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_putchar(char c);
int				ft_putstr(char *s);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst,
								void *(*f)(void *),
								void (*del)(void *));

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
char			*ft_strndup(const char *src, int n);

#endif
