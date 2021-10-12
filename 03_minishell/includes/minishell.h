/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/10/12 17:31:30 by hkwon            ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft.h"

# define PATH_MAX 1024
# define BLTIN_NUM 7

# define NONE 0
# define CMD 1
# define ARG 2
# define REDIRECT 4
# define PIPE 8
# define S_QUOTE 16
# define D_QUOTE 32

# define RD_IN 1
# define RD_OUT 2
# define RD_APPEND 4
# define RD_HEREDOC	8
# define COMMAND 16
# define ARGUMENT 32

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

typedef struct s_mini		t_mini;
typedef struct s_cmd		t_cmd;
typedef struct s_token		t_token;
typedef struct s_parse		t_parse;
typedef struct s_history	t_history;
typedef struct s_read		t_read;

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
	int		type;
	t_token	*token;
	t_cmd	*next;
	t_cmd	*prev;
};

struct s_mini
{
	t_cmd			*cmd;
	t_history		*hist;
	int				exit_status;
	pid_t			pid;
	int				sig_flag;
	int				pipe_flag;
	int				pre_flag;
	int				re_flag;
	int				fds[2];
	char			*line;
	struct termios	term_sh;
	struct termios	term_ori;
};

extern t_mini				g_mini;

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
** init
*/
void	init_shell(char ***en, char *envp[]);
void	show_prompt(void);
/*
** parsing
*/
t_cmd	*parse_start(char *line);
char	**parse_line(char *line);
t_token	*parse_token(char *cmd_list);
char	**parse_token_arr(char **args, char *cmd_list);
t_token	*make_token_list(char **args);

/*
** execute
*/
char	**execute(char **args, char **en);

/*
** builtin
*/
char	*blt_str(int i);
char	**(*blt_func(int i))(char **args, char **en);
char	**ft_echo(char **args, char **en);
char	**ft_cd(char **args, char **en);
char	**ft_pwd(char **args, char **en);
char	**ft_export(char **args, char **en);
char	**ft_unset(char **args, char **en);
char	**ft_env(char **args, char **en);
char	**ft_exit(char **args, char **en);

#endif
