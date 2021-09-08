/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 05:44:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/08 16:07:29 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Execute process
// execve : 첫번째 인자로 받은 path의 파일을 실행하고 argv, envp를 인자로 전달한다.
// 우리가 명령어로 생각하는 'ls', 'echo'등은 실은 $PATH 경로 안에 있는 실행파일이다. 즉 프로그램을 실행해 명령어를 사용한다는 뜻이다.
// execve는 해당 프로세스는 종료하고 새로운 프로세스를 생성 및 실행을 한다.
// 종료되기 때문에 자식 프로세스를 fork()로 생성하고 자식 프로세스에서 exec를 하는게 일반적이다.
// fork()는 pipe()함수를 실행한다면 dup2()함수로 프로세스 간의 입출력을 연결해주기위해 사용한다.
int	exe_process(char *exe, char **args, char **en)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(exe, args, en) == -1)
			printf("Error : permission denied\n");
	}
	else if (pid < 0)
		printf("Error : Failed fork");
	else
		wait(&pid);
	return (1);
}

char	*ft_find_env(char *name, char **env)
{
	int	i;

	i = -1;
	if (ft_strlen(name) == 1 && name[0] == '~')
		name = "$HOME";
	name += (name[0] == '$');
	while (env[++i])
	{
		if (!ft_strncmp(name, env[i], ft_strlen(name)))
			if (env[i][ft_strlen(name)] == '=')
				return (ft_strchr(env[i], '=') + 1);
	}
	return ("");
}

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (s1);
}

// Find command
void	find_cmd(char **args, char **en)
{
	char	**p;
	char	*path;
	int		i;

	p = ft_token(ft_find_env("$PATH", en), ":");
	path = ft_strnew(PATH_MAX);
	i = -1;
	while (p[++i])
	{
		ft_strclr(path);
		ft_strcat(path, p[i]);
		if (args[0][0] != '/')
			ft_strcat(path, "/");
		ft_strcat(path, args[0]);
		if (access(path, F_OK) != -1)
		{
			exe_process(path, args, en);
			break ;
		}
	}
	if (!p[i])
		printf("command not found");
	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
	free(path);
}

// Execute command
char	**execute(char **args, char **en)
{
	int	i;

	i = -1;
	if (!args || !*args || !**args)
		return (en);
	while (++i < BLTIN_NUM)
		if (!ft_strcmp(args[0], blt_str(i)))
			return ((*blt_func(i))(args, en));
	if (access(args[0], F_OK) != -1)
		exe_process(args[0], args, en);
	else
		find_cmd(args, en);
	return (en);
}
