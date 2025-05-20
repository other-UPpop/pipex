/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:04:50 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 03:14:12 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ok_access(t_arg arg)
{
	if (access(arg.c_arg[3], (F_OK)) == 0)
		return (0);
	return (1);
}

static int	wait_free(t_pid pid, t_arg arg)
{
	int	status1;
	int	status2;
	int	error_n;
	int	grep;

	status1 = 0;
	status2 = 0;
	error_n = 0;
	grep = 0;
	if (ft_strnstr(arg.c_arg[2], "grep", ft_strlen(arg.c_arg[2])))
		grep = 1;
	if (access(arg.c_arg[3], W_OK) != 0)
		error_n = 1;
	waitpid(pid.p1, &status1, 0);
	waitpid(pid.p2, &status2, 0);
	free_args(arg.c_arg);
	free_args(arg.s_arg);
	// printf("1%d\n", status1);
	// printf("2%d\n", status2);
	if (status1 == 0 && status2 == 0)
		return (0);
	else if (error_n == 1 || grep == 1 || status2 == 256)
		return (1);
	else if (status2 == 32512 || status2 != 0)
		return (127);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_fd	fd;
	t_pid	pid;
	int		open;
	int		pipefd[2];

	open = 0;
	if (argc < 5)
		return (1);
	get_arg_ck(argc, argv, &arg);
	fd.get_fd = get_file_open(arg, envp);
	open = ok_access(arg);
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
	open = wait_free(pid, arg);
	return (open);
}
