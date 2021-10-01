/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/26 13:56:12 by hkwon            ###   ########.fr       */
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

# define CMD 1
# define REDIRECT 2
# define PIPE 3
# define ARG 4

# define RD_IN 1
# define RD_OUT 2
# define RD_APPEND 3
# define RD_HEREDOC	4
# define VALUE 5

// typedef struct s_minishell	t_minishell;
typedef struct s_cmd		t_cmd;
typedef struct s_mini		t_mini;

// 환경변수를 저장할 필요가 있다면 key/value값을 나눠 저장하자.
// "="을 기준으로 나눈다.
// struct s_env
// {
// 	char	*key;
// 	char	*value;
// 	t_env	*next;
// };

// typedef struct s_cmd
// {
// 	char *cmd;
// 	char *buff;
// 	//t_minishell next_perv
// }				t_cmd;

// typedef struct s_minishell
// {
// 	struct	s_minishell *next;
// 	struct	s_minishell *prev;
// 	struct	s_minishell *head;
// 	t_cmd	*cmd;
// 	int		exit_status;
// 	int		pipe_flag;
// 	int		pre_flag;
// 	int		re_flag;
// 	int		fds[2];
// }	t_minishell;

// // cmd struct
struct	s_cmd
{
	// char	*name;
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
t_mini	*parse(char	*line);
char	**separate(char *line, char c);
t_cmd	*get_token(char *line);
void	ft_strskip(char **str, char *charset);

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