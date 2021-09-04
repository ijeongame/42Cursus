/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:10:37 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/04 14:37:22 by kwonhyukbae      ###   ########.fr       */
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

typedef struct s_minishell
{
}	t_minishell;

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
builtin commands
*/
char	*blt_str(int i);
int		(*blt_func(int i))(char *line, char **en);
int		ft_echo(char *line, char **en);
int		ft_cd(char *line, char **en);
int		ft_pwd(char *line, char **en);
int		ft_export(char *line, char **en);
int		ft_unset(char *line, char **en);
int		ft_env(char *line, char **en);
int		ft_exit(char *line, char **en);

#endif