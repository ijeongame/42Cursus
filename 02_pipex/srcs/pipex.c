#include <unistd.h>

int main(int ac, char *av[])
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	//bash 명령어를 실행하는 shell 스크립트를 만들어야한다.
	//인자가 5개 이하인지 확인
	//pipe함수를 이용
	if (argc != 5)
		return (0);
	pipe(pipefd);
	//양 끝단의 redirection 기능부터 구현.
	//file descriptor 개념을 숙지하기.
	//notion 확인
}

