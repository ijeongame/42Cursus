/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:26:18 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/08 15:02:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*blt_str(int i)
{
	char	*blt_str[BLTIN_NUM + 1];

	blt_str[0] = "echo";
	blt_str[1] = "cd";
	blt_str[2] = "pwd";
	blt_str[3] = "export";
	blt_str[4] = "unset";
	blt_str[5] = "env";
	blt_str[6] = "exit";
	blt_str[7] = NULL;
	return (blt_str[i]);
}

// 함수포인터를 이용하여 내장 기능을 수행한다.
// 함수포인터를 사용하는 이유는 ?
// exit pwd cd
// echo env unset export
// 이차원배열을 만들어서 char *line -> char **cmd로 내장함수를 저장할 수 있게 만들자.
// 함수포인터를 사용했을 때 인자값이 고정이 되어버린다.
char	**(*blt_func(int i))(char **args, char **en)
{
	char	**(*blt_func[BLTIN_NUM])(char **args, char **en);

	blt_func[0] = &ft_echo;
	blt_func[1] = &ft_cd;
	blt_func[2] = &ft_pwd;
	blt_func[3] = &ft_export;
	blt_func[4] = &ft_unset;
	blt_func[5] = &ft_env;
	blt_func[6] = &ft_exit;
	return (blt_func[i]);
}
