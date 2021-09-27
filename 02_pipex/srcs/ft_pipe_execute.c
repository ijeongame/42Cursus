/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:27:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/27 16:57:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**ft_pipe_path(char *envp[])
{
	int		i;
	char	**paths;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
	}
	return (NULL);
}

void	ft_pipe_execute(t_info *info, char *cmd, char *envp[])
{
	int	i;

	info->command = ft_parsing(cmd);
	info->paths = ft_pipe_path(envp);
	if (info->paths == NULL)
		ft_pipe_exit("Error : no PATH\n");
	i = -1;
	while (info->paths[++i])
	{
		info->path = ft_strjoin(info->paths[i], "/");
		info->path_cmd = ft_strjoin(info->path, info->command[0]);
		if (access(info->path_cmd, F_OK | X_OK) == 0)
		{
			if (execve(info->path_cmd, info->command, envp) == -1)
				ft_pipe_exit("Error : command not found\n");
		}
		free(info->path);
		free(info->path_cmd);
	}
	ft_free(info->command);
	ft_free(info->paths);
	ft_pipe_exit("Error : command not found\n");
}
