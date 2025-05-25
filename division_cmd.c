/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:05 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 03:29:34 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**div_cmd(char **av)
{
	char	**cmd;
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (av[i++])
		count++;
	cmd = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!cmd)
		return (NULL);
	i = 0;
	while (i < count)
	{
		cmd[i] = ft_strdup(av[i + 1]);
		if (!cmd[i])
			free_arg(cmd);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
