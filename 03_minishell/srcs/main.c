/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:59:00 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/08 04:48:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 환경변수를 조작할 시 malloc과 free에 있어서 main 변수 envp를 그대로 사용하면
// error가 발생한다고 한다.
void	init_env(char ***en, char *envp[])
{
	int	i;
	int	j;

	i = -1;
	while (envp[++i])
		;
	(*en) = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (envp[++i])
	{
		(*en)[i] = (char *)malloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*en)[i][j] = envp[i][j];
		(*en)[i][j] = 0;
	}
	(*en)[i] = NULL;
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	// 환경변수를 따로 저장할 문자열을 만들 것인가?
	// 환경변수를 바로 사용할 것인가?
	// 바로 사용했을 때 문제가 될 부분은 없는가?
	// 수정할 일이 생기면 거기에 맞춰서 작성.
	char	**en;

	init_env(&en, envp);
	minishell(en);
	(void)argc;
	(void)argv;
	return (0);
}

// 언제 error기 1이 나오고 0이 나오는지