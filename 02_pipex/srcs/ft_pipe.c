/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:42:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/12 03:35:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe_exit(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	if (argc != 5)
		ft_pipe_exit("Check Argument: ./pipex file1 cmd1 cmd2 file2\n");
	//다음 if문이 실행된다는 의미는 pipe가 제대로 생성되지 않았다는 것을 의미
	//pipe가 생성됐다면 pipe_fd[0]은 읽기용 파일 디스크립터, pipe_fd[1]은 쓰기용 파일 디스크립터가 된다.
	ft_pipe_process(&info, argv, envp);
	return (0);
}
