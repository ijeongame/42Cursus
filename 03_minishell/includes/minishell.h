/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/10/04 14:11:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <termios.h>
# include "libft.h"

# define PATH_MAX 1024
# define BLTIN_NUM 7

# define NONE 0
# define CMD 1
# define REDIRECT 2
# define PIPE 3
# define ARG 4

# define RD_IN 5
# define RD_OUT 6
# define RD_APPEND 7
# define RD_HEREDOC	8

typedef struct s_mini	t_mini;
typedef struct s_cmd	t_cmd;
// typedef struct s_token	t_token;
typedef struct s_parse	t_parse;

struct s_parse
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	**pstr;
};

// // token struct
// struct s_token
// {
// 	int		type;
// 	char	*arg;
// 	t_token	*next;
// 	t_token	*prev;
// };

// cmd struct
struct	s_cmd
{
	//t_token *token;
	int		type;
	char	*arg;
	t_cmd	*next;
	t_cmd	*prev;
};

// 하면서 필요한 부분을 구조체에 넣어서 
struct s_mini
{
	t_cmd	*cmd;
	int		exit_status;
	int		pipe_flag;
	int		pre_flag;
	int		re_flag;
	int		fds[2];
};

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
** parsing
*/
t_cmd	*parse(char	*line);
char	**ft_parsing(char *cmd);
void	ft_strskip(char **str, char *charset);
// t_cmd	*get_token(char *line);

/*
** execute commands
*/
char	**execute(char **args, char **en);

/*
** builtin commands
*/
char	*blt_str(int i);
char	**(*blt_func(int i))(char **args, char **en);

/*
** builtin function
*/
char	**ft_echo(char **args, char **en);
char	**ft_cd(char **args, char **en);
char	**ft_pwd(char **args, char **en);
char	**ft_export(char **args, char **en);
char	**ft_unset(char **args, char **en);
char	**ft_env(char **args, char **en);
char	**ft_exit(char **args, char **en);

// utils
char	*ft_strnew(size_t size);
void	*ft_malloc(size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncat(char *s1, const char *s2, size_t n);
void	ft_strclr(char *s);
char	*ft_strcat(char *s1, const char *s2);

#endif