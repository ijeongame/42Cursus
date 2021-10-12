/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 04:15:24 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/12 04:15:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info
{
	int		fd[2];
	int		f_in;
	int		f_out;
	char	**command;
	char	**paths;
	char	*path;
	char	*path_cmd;
}	t_info;

void	ft_pipe_process(t_info *info, char *argv[], char *envp[]);
void	ft_pipe_execute(t_info *info, char *cmd, char *envp[]);
void	ft_pipe_exit(char *error);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
