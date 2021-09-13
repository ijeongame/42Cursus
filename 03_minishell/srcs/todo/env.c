/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:32:20 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/07 20:27:00 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_env(char ***en, char *envp[])
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (envp[++i])
// 		;
// 	(*en) = (char **)malloc(sizeof(char *) * i);
// 	i = -1;
// 	while (envp[++i])
// 	{
// 		(*en)[i] = (char *)malloc(PATH_MAX + 1);
// 		j = -1;
// 		while (envp[i][++j])
// 			(*en)[i][j] = envp[i][j];
// 		(*en)[i][j] = 0;
// 	}
// 	(*en)[i] = NULL;
// 	return ;
// }