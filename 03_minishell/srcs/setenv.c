/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:18:44 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/09 17:21:17 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int k;

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

void	ft_strclr(char *s)
{
	int i;

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

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (k < n && s2[k] != '\0')
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (s1);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (diff);
}

static void	free_tmp(char **arg)
{
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

void	ft_tabfree(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

char	*ft_find_env(char *name, char **env)
{
	int	i;

	i = -1;
	(ft_strlen(name) == 1 && name[0] == '~') ? name = "$HOME" : 0;
	name += (name[0] == '$');
	while (env[++i])
	{
		if (!ft_strncmp(name, env[i], ft_strlen(name)))
			if (env[i][ft_strlen(name)] == '=')
				return (ft_strchr(env[i], '=') + 1);
	}
	return ("");
}

char	**replace(char **args, char **env)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(args[1]);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(env[i], args[1]);
	ft_strcat(env[i], "=");
	ft_strcat(env[i], args[2]);
	return (env);
}

char	**create_new(char **args, char **en)
{
	char	***e;
	char	**env;
	int		i;

	i = -1;
	e = &en;
	while ((*e)[++i])
		NULL;
	env = (char **)ft_malloc(sizeof(char *) * (i + 1));
	i = -1;
	while ((*e)[++i])
		env[i] = ft_strdup((*e)[i]);
	ft_tabfree(en);
	env[i] = (char *)ft_malloc(PATH_MAX + 1);
	ft_strncat(env[i], args[1], ft_strlen(args[1]));
	ft_strncat(env[i], "=", 1);
	ft_strncat(env[i], args[2], ft_strlen(args[2]));
	e = &env;
	return (*e);
}

char	**one_arg(char **args, char **en)
{
	int		i;
	int		j;
	char	**tmp;

	i = (args[1][0] == '"');
	j = 0;
	tmp = (char **)ft_malloc(sizeof(char *) * 3);
	tmp[0] = NULL;
	tmp[1] = ft_strnew(sizeof(args[1]));
	tmp[2] = ft_strnew(sizeof(args[1]));
	while (args[1][i] != '=' && args[1][i])
		tmp[1][j++] = args[1][i++];
	if (!args[1][i])
	{
		free(tmp);
		return (en);
	}
	j = 0;
	while (args[1][++i] != '"' && args[1][i])
		tmp[2][j++] = args[1][i];
	en = cmd_setenv(tmp, en);
	free_tmp(tmp);
	return (en);
}

char	**cmd_setenv(char **args, char **en)
{
	if (!args[1])
		return (en);
	if (!args[2])
		return (one_arg(args, en));
	if (ft_find_env(args[1], en)[0] != 0)
		return (replace(args, en));
	return (create_new(args, en));
}
