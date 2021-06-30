/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:42:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/30 21:42:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_in(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	//dup : fd로 전달받은 파일 서술자를 복제하여 반환한다. dup가 돌려주는 파일 서술자는 가장 낮은 서술자를 반환한다. 성공시 파일 서술자, 실패시 -1
	//dup2 : 새 서술자의 값을 fd2로 지정한다. 만일 fd2가 이미 열려있으면 fd2를 닫은 후 복제가 된다. 성공시 파일 서술자, 실패시 -1
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int main(int ac, char *av[])
{
	redirect_in(av[1]);
	redirect_out(av[2]);
	//execve(const char *filneme, char *const av[], char *const envp[])
	//filename이 가리키는 파일을 실행한다. av와 envp는 포인터 배열로 filename의 인자로 들어간다.
	// execve("/bin/cat", 0, 0);
	printf("stdout test\n");
	return (0);
	// int		pipefd[2];
	// int		status;
	// pid_t	pid;

	// //bash 명령어를 실행하는 shell 스크립트를 만들어야한다.
	// //인자가 5개 이하인지 확인
	// //pipe함수를 이용
	// if (argc != 5)
	// 	return (0);
	// pipe(pipefd);
	// //양 끝단의 redirection 기능부터 구현.
	// //file descriptor 개념을 숙지하기.
	// //notion 확인
}
