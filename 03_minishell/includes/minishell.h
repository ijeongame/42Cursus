/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/10/06 23:52:40 by hkwon            ###   ########.fr       */
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
# define PIPE 4
# define ARG 8
# define S_QUOTE 16
# define D_QUOTE 32

# define RD_IN 1
# define RD_OUT 2
# define RD_APPEND 4
# define RD_HEREDOC	8

typedef struct s_mini	t_mini;
typedef struct s_cmd	t_cmd;
typedef struct s_token	t_token;
typedef struct s_parse	t_parse;

/*
** parse struct
*/
struct s_parse
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	**pstr;
};

/*
** token struct
*/
struct s_token
{
	int		type;
	char	*arg;
	t_token	*next;
	t_token	*prev;
};

/*
** cmd struct
*/
struct	s_cmd
{
	t_token	*token;
	t_cmd	*next;
	t_cmd	*prev;
};

/*
** minishell struct
*/
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
t_cmd	*parse_start(char *line);
char	**parse_line(char *cmd);
t_token	*parse_token(char *cmd_list);
t_token	*parse_token_arg(char **args, char *cmd_list);

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