/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/08 16:09:26 by hkwon            ###   ########.fr       */
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

// typedef struct s_minishell	t_minishell;
// typedef struct s_cmd		t_cmd;
// typedef struct s_env		t_env;

// 하면서 필요한 부분을 구조체에 넣어서 
// struct s_minishell
// {
// 	t_cmd	cmd;
// };

// 환경변수를 저장할 필요가 있다면 key/value값을 나눠 저장하자.
// "="을 기준으로 나눈다.
// struct s_env
// {
// 	char	*key;
// 	char	*value;
// 	t_env	*next;
// };

// cmd struct
// struct s_cmd
// {
// 	char	*cmd;
// 	t_list	*args;
// };

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

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
char	**ft_token(char *s, char *sep);
char	*ft_strnew(size_t size);

#endif