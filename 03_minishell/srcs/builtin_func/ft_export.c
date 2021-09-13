/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:12:47 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/08 12:54:49 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// 만약 파이프라인 뒤쪽에 있다면 export는 실행되지 않는다  뒤에있는지 여부를확인하는 플레그가 필요할듯?
// 어디까지 구현할지 상담
void	print_export(char **en)
{
	int i;

	i = -1;
	while (en[++i])
	{
		write(1, "declare -x ",ft_strlen("declare -x "));
		ft_putendl_fd(en[i], 1);
	}
}

void add_export(char *str, char **new, int i)
{
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
}

int check_export(char *str, char ***en)
{
	int i;
	char **new;

	i = -1;
	while((*en)[++i])
		if (!ft_strncmp((*en)[i], str, ft_strlen(str)))
		{
			(*en)[i] = ft_strdup(str);
			return (1);
		}
	if (!(new = malloc(sizeof(char*) * (i + 2))))
		return (0);
	i = -1;
	while ((*en)[++i])
		new[i] = ft_strdup((*en)[i]);
	add_export(str, new, i);
	*en = new;
	return (1);
}

// 만약 글로벌 변수를 사용하고 싶지 않다면 삼중포인터로 가져와야 할거같다.
int	ft_export(char *line, char **en)
{
	int i;
	int status;
	char **buff;
	// char *key;
	// char *value;

	status = 0;
	buff = ft_split(line, ' ');
	i = 0;

	if(!buff[1])
		print_export(g_envp);
	else
	{
		// " \ "문자 제거는 나중에 하자
		// key=value로 들어왔는지 확인한다음
		// 아니라면 key만 저장한다.
		//같은것이 있는지 찾는다
		// 같은것이 있다면 free해주고 새로 기입한다.
		// 없다면 생성
		// key=value형태인데 key가 숫자면 안된다.
		// key에 " - " 가 있으면 에러
		
		if(ft_strchr(buff[1], '='))
			status = check_export(buff[i],&g_envp);
		else
			while(buff[++i])
			{
				status = check_export(buff[i],&g_envp);
			}
	}
	(void)en;
	return (status);
}
