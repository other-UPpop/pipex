/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:05 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 22:00:39 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*str_join(char **cmd, size_t j, size_t i, char **str)
{
	char	*tmp;

	tmp = ft_strjoin(cmd[j], " ");
	free (cmd[j]);
	cmd[j] = ft_strjoin(tmp, str[i + 1]);
	free (tmp);
	return (cmd[j]);
}

static char	*sleep_cmd(char **cmd, char **str, size_t *i, size_t j)
{
	char	*tmp;
	char	*str;
	int		num;

	num = 0;
	while (ft_atoi(str[*i + 1]) != 0
		&& ft_isdigit(ft_atoi(str[*i + 1])) != 0)
	{
		num += ft_atoi(str[*i + 1]);
		*i++;
	}
	tmp = ft_strjoin(cmd[j], " ");
	free (cmd[j]);
	str = ft_itoa(num);
	cmd[j] = ft_strjoin(tmp, str);
	free (str);
	free (tmp);
	return (cmd[j]);
}

static char	**put_cmd(char **cmd, char **str, t_error *err)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][0] != '-')
		{
			cmd[j] = ft_strdup(str[i]);
			while ((str[i + 1] && str[i + 1][0] == '-')
				|| ft_strncmp(cmd[j], "grep", 5) == 0)
			{
				cmd[j] = str_join(cmd, j, i, str);
				i++;
			}
			if (ft_strncmp(cmd[j], "sleep", 6) == 0)
				cmd[j] = sleep_cmd(cmd, str, &i, j);
			j++;
		}
		i++;
	}
	return (cmd);
}

static char	**div_str(char **str, t_error *err)
{
	char	**cmd;
	int		count;

	count = count_cmd(str);
	cmd = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!cmd)
		return (NULL);
	put_cmd(cmd, str, err);
	return (cmd);
}
