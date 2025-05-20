/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:04:50 by rohta             #+#    #+#             */
/*   Updated: 2025/05/20 15:13:01 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_fd	fd;
	t_pid	pid;
	int		pipefd[2];

	if (argc < 5)
		return (1);
	get_arg_ck(argc, argv, &arg);
	fd.get_fd = get_file_open(arg);
	fd.out_fd = out_file_open(arg, fd);
	if (pipe_init(pipefd) == 1)
		return (-1);
	pid.p1 = fork();
	if (pid.p1 == 0)
		pid1_cmd(arg, fd, pipefd, envp);
	pid.p2 = fork();
	if (pid.p2 == 0)
		pid2_cmd(arg, fd, pipefd, envp);
	parent_process_close(pipefd, fd);
	waitpid(pid.p1, NULL, 0);
	waitpid(pid.p2, NULL, 0);
	free_args(arg.c_arg);
	free_args(arg.s_arg);
	return (0);
}
