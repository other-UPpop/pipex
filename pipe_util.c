/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:13:33 by rohta             #+#    #+#             */
/*   Updated: 2025/05/20 16:44:41 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_init(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	parent_process_close(int pipefd[2], t_fd fd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd.get_fd);
	close(fd.out_fd);
}

char	*str_join(char **cmd, size_t j, size_t i, char **aft_str)
{
	char	*tmp;

	tmp = ft_strjoin(cmd[j], " ");
	free (cmd[j]);
	cmd[j] = ft_strjoin(tmp, aft_str[i + 1]);
	free (tmp);
	return (cmd[j]);
}

char	*sleep_cmd(char **cmd, char **aft_str, size_t *i, size_t j)
{
	char	*tmp;
	char	*str;
	int		num;

	num = 0;
	while (ft_atoi(aft_str[*i + 1]) != 0
		|| ft_isdigit(ft_atoi(aft_str[*i + 1])) == 1)
	{
		num += ft_atoi(aft_str[*i + 1]);
		*i += 1;
	}
	tmp = ft_strjoin(cmd[j], " ");
	free (cmd[j]);
	str = ft_itoa(num);
	cmd[j] = ft_strjoin(tmp, str);
	free (str);
	free (tmp);
	return (cmd[j]);
}
