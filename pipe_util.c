/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:13:33 by rohta             #+#    #+#             */
/*   Updated: 2025/05/19 21:21:23 by rohta            ###   ########.fr       */
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
