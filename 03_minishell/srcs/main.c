/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:59:00 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/04 12:49:57 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	**en;

	while (*envp)
		printf("%s\n", *envp++);
	init_env(&en, envp);
	minishell(en);
	(void)argc;
	(void)argv;
	return (0);
}
