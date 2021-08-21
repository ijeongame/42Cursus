/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:57:53 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/08/21 20:13:00 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe_exit(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(0);
}

void	ft_pipe(int ac, char *av[])
{
	int		in;
	int		out;
	int		pipefd[2];
	pid_t	pid_in;
	pid_t	pid_out;
	//fork 2번을 해서 child 2개를 만들어 통신을 하게, 자식-자식 파이프 통신
	//1개를 만들 부모-자식 파이프 통신
	//자식-자식 vs 부모-자식 -> minishell을 갔을 때 원래 실행해야하는 부모 단의 프로세스가 날아간다.
	//-> 에러가 발생했는지 정확히 모른다.
	in = open(av[1], O_RDONLY);
	ft_pipe_open(in, &pid_in, pipefd, av[2]);
	out = open(av[4], O_WRONLY);
	pid_out = fork();
	if (pid_out == -1)
		ft_pipe_exit("Failed to fork process");
	else
		ft_pipe_out(pipefd, out, av[3]);
	if (out == -1)
		ft_pipe_exit("Failed output file");
	if (pipe(pipefd) == -1)
		ft_pipe_exit("Failed to create pipe");
}

void	ft_pipe_open(int file, pid_t *pid, int pipefd[2], char *av)
{
	pid = fork();
	if (file == -1)
		ft_pipe_exit("Failed input file");
	if (pid == -1)
		ft_pipe_exit("Failed to fork process");
	else
		ft_pipe_in(pipefd, file, av);
}

void	ft_pipe_in(int pipefd[2], int fd, char *cmd)
{
	char	**args;

	close(pipefd[0]);
	args = ft_split(cmd, ' ');
	//dup를 사용해 파이프 복사
	//파이프 닫아주기
	if (dup2(fd, 0) == -1)
		ft_pipe_exit("Error");
	if (dup2(pipefd[1], 1) == -1)
		ft_pipe_exit("Error");
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, NULL) == -1);
			ft_pipe_exit("Error");

	}
	else
		//실행
	// ft_pipe_free(args);
	close(fd);
	close(pipefd[1]);
	wait(NULL);
}

void	ft_pipe_out(int pipefd[2], int fd, char *cmd)
{
	char	**args;

	close(pipefd[1]);
	args = ft_split(cmd, ' ');
	//dup를 사용해 파이프 복사
	//파이프 닫아주기
	if (dup2(fd, 0) == -1)
		ft_pipe_exit("Error");
	if (dup2(pipefd[1], 1) == -1)
		ft_pipe_exit("Error");
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, NULL) == -1);
			ft_pipe_exit("Error");

	}
	else
		//실행
	// ft_pipe_free(args);
	close(fd);
	close(pipefd[0]);
	wait(NULL);
}

// void	ft_exec(char *cmd, char **args)
// {

// }

// void	ft_paths(char *cmd, char *args, char **path)
// {

// }