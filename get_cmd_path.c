/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:19:42 by rohta             #+#    #+#             */
/*   Updated: 2025/05/20 15:23:19 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	count_cmds(char	**aft_str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (aft_str[i])
	{
		if (aft_str[i][0] != '-' || i == 0)
			count++;
		i++;
	}
	return (count);
}

char	**put_cmd(char **cmd, char **aft_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (aft_str[i])
	{
		if (aft_str[i][0] != '-')
		{
			cmd[j] = ft_strdup(aft_str[i]);
			while ((aft_str[i + 1] && aft_str[i + 1][0] == '-')
				|| ft_strncmp(cmd[j], "sleep", 6) == 0
				|| ft_strcmp(cmd[j], "grep", 5) == 0)
			{
				cmd[j] = str_join(cmd, j, i, aft_str);
				i++;
			}
			j++;
		}
		i++;
	}
	return (cmd);
}

static char	*get_all_path(char **envp)
{
	size_t	i;
	char	*all_path;

	i = 0;
	all_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_path = ft_substr(envp[i], 6, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	return (all_path);
}

static char	*get_ok_path(char **div_path, char *ok_path, char *arg)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (div_path[i])
	{
		tmp = ft_strjoin(div_path[i], "/");
		ok_path = ft_strjoin(tmp, arg);
		if (!ok_path)
			return (NULL);
		free(tmp);
		if (access(ok_path, (X_OK | F_OK)) == 0)
		{
			free_args(div_path);
			return (ok_path);
		}
		free(ok_path);
		i++;
	}
	free_args(div_path);
	return (NULL);
}

char	*get_cmd_path(char *arg, char **envp)
{
	char	*all_path;
	char	*ok_path;
	char	**div_path;

	ok_path = NULL;
	all_path = get_all_path(envp);
	if (!all_path)
		return (NULL);
	div_path = ft_split(all_path, ':');
	if (!div_path)
		return (NULL);
	free(all_path);
	ok_path = get_ok_path(div_path, ok_path, arg);
	return (ok_path);
}
