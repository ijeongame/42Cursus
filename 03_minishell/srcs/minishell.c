/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:45:48 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/08 16:05:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// | 로 들어왔을 때 파싱해서 저장하는 게 필요할 것 같아요.
// "" $문자만 읽어오도록 하자. -> 유효성 검사 -> 파싱하는 부분에서 검사
static char	*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

// Parsing
char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}

static int	count_chars(char *s, char *sep)
{
	int	i;
	int	chars;

	chars = 0;
	while (s[chars])
	{
		i = 0;
		while (sep[i])
		{
			if (s[chars] == sep[i++])
				return (chars);
		}
		chars++;
	}
	return (chars);
}

static int	count_parts(char *s, char *sep)
{
	int	i;
	int	parts;

	parts = 0;
	while (*s)
	{
		i = 0;
		while (sep[i])
		{	
			if (*s == sep[i++])
				parts++;
			s++;
		}
	}
	return (parts + 1);
}

// tokenization : separate using pipe
char	**ft_token(char *s, char *sep)
{
	char	**token;
	int		parts;
	int		chars;
	int		i;
	int		j;

	parts = count_parts(s, sep);
	token = (char **)malloc(sizeof(char *) * parts + 1);
	if (!token)
		return (NULL);
	i = 0;
	while (i < parts)
	{
		j = 0;
		chars = count_chars(s, sep);
		if (s && !chars)
			s++;
		if (s && chars)
			token[i] = ft_strnew(chars);
		while (*s && j < chars && chars > 0)
			token[i][j++] = *(s++);
		if (token[i] || chars)
			i++;
		if (!*s)
			break ;
	}
	token[i] = NULL;
	return (token);
}

// run command
// separate using "\t\n "
char	**run_cmd(char **cmd, char **en)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[j])
	{
		args = ft_token(cmd[j], "\t\n ");
		en = execute(args, en);
		free(cmd[j]);
		j++;
		while (args[i])
		{
			printf("args = %s\n", args[i]);
			free(args[i++]);
		}
		if (args)
			free(args);
	}
	return (en);
}

void	minishell(char **en)
{
	int		status;
	char	*line;
	char	**cmd;

	// 1. get_next_line을 통해 한 줄씩 읽어오면서
	// "|" 를 만나는 시점을 기준으로 command를 파싱한다.
	status = 1;
	while (status)
	{
		write(1, "minishell>", ft_strlen("minishell>"));
		line = read_line();
		// parsing pipe
		// get_next_line->getch()함수
		// enter 예외처리
		cmd = ft_token(line, "|");
		en = run_cmd(cmd, en);
		if (!en)
			status = 0;
		free(cmd);
		free(line);
	}
}

// 구조체 t_cmd
// history -> cmd next/prev
// exit code -> option?