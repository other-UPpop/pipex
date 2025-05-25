/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:28:31 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 01:24:48 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipe_create(t_arg *arg, t_pidfd *pidfd)
{
	if (pipe(pidfd->pipefd) == -1)
	{
		free_args(arg);
		perror("pipe");
		return (-1);
	}
	return (0);
}

static void	parent_close(t_pidfd *pidfd)
{
	close(pidfd->pipefd[0]);
	close(pidfd->pipefd[1]);
	close(pidfd->in_fd);
	close(pidfd->out_fd);
}

void	print_arg(t_arg *arg)
{
	int i = 0;
	while (arg->c_arg[i])
	{
		printf("%s\n", arg->c_arg[i++]);
	}
}

static void	wait_free(t_arg *arg, t_pidfd *pidfd)
{
	int	status1;
	int	status2;

	status1 = 0;
	status2 = 0;
	waitpid(pidfd->p1, &status1, 0);
	waitpid(pidfd->p2, &status2, 0);
	print_arg(arg);
	//free_args(arg);
}

void	pipex(t_arg *arg, t_pidfd *pidfd, t_error *err, char **envp)
{
	if (pipe_create(arg, pidfd) == -1)
		return ;
	do_cmd(arg, pidfd, err, envp);
	parent_close(pidfd);
	wait_free(arg, pidfd);
}
