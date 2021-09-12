/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:16:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/12 17:23:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_pipe_in(t_info *info, char *argv[], char *envp[])
{
	info->f_in = open(argv[1], O_RDONLY);
	if (info->f_in < 0)
		ft_pipe_exit("Error : input file\n");
	if (dup2(info->fd[1], STDOUT_FILENO) == -1)
		ft_pipe_exit("Error : dup failed1\n");
	if (dup2(info->f_in, STDIN_FILENO) == -1)
		ft_pipe_exit("Error : dup failed2\n");
	close(info->fd[0]);
	close(info->f_in);
	close(info->fd[1]);
	ft_pipe_execute(info, argv[2], envp);
}

void	ft_pipe_out(t_info *info, char *argv[], char *envp[])
{
	info->f_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->f_out < 0)
		ft_pipe_exit("Error : output file\n");
	if (dup2(info->fd[0], STDIN_FILENO) == -1)
		ft_pipe_exit("Error : dup failed3\n");
	if (dup2(info->f_out, STDOUT_FILENO) == -1)
		ft_pipe_exit("Error : dup failed4\n");
	close(info->fd[1]);
	close(info->f_out);
	close(info->fd[0]);
	ft_pipe_execute(info, argv[3], envp);
}

void	ft_pipe_process(t_info *info, char *argv[], char *envp[])
{
	int	num;

	if (!ft_strncmp(argv[1], "here_doc"))
	{
		num = 3;
		here_doc(argc, argv)
	}
}
