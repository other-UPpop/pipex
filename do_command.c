/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:25:26 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 00:33:17 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execve_cmd1(char *cmd, t_arg *arg, t_error *err, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		if (err->log < 2)
			error_print_cmd(args[0], err);
		free_arg(args);
		free_args(arg);
		err->return_num = 1;
		exit(err->return_num);
	}
	execve(cmd_path, args, envp);
	if (err->log < 2)
		error_print_cmd(args[0], err);
	free(cmd_path);
	free_arg(args);
	free_args(arg);
	exit(1);
}

static void	execve_cmd2(char *cmd, t_arg *arg, t_error *err, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		if (err->log < 2)
			error_print_cmd(args[0], err);
		free_arg(args);
		free_args(arg);
		err->return_num = 127;
		exit(err->return_num);
	}
	execve(cmd_path, args, envp);
	if (err->log < 2)
		error_print_cmd(args[0], err);
	free(cmd_path);
	free_arg(args);
	free_args(arg);
	exit(127);
}

static void	pid1_cmd(t_arg *arg, t_pidfd *pidfd, t_error *err, char **envp)
{
	if (err->in_file == false)
	{
		free_args(arg);
		exit(0);
	}
	dup2(pidfd->in_fd, STDIN_FILENO);
	dup2(pidfd->pipefd[1], STDOUT_FILENO);
	close(pidfd->pipefd[0]);
	close(pidfd->pipefd[1]);
	close(pidfd->in_fd);
	close(pidfd->out_fd);
	execve_cmd1(arg->c_arg[1], arg, err, envp);
	free_args(arg);
	exit(0);
}

static void	pid2_cmd(t_arg *arg, t_pidfd *pidfd, t_error *err, char **envp)
{
	if (err->out_file == false)
	{
		free_args(arg);
		exit(1);
	}
	dup2(pidfd->pipefd[0], STDIN_FILENO);
	dup2(pidfd->out_fd, STDOUT_FILENO);
	close(pidfd->pipefd[0]);
	close(pidfd->pipefd[1]);
	close(pidfd->in_fd);
	close(pidfd->out_fd);
	execve_cmd2(arg->c_arg[2], arg, err, envp);
	free_args(arg);
	exit(127);
}

void	do_cmd(t_arg *arg, t_pidfd *pidfd, t_error *err, char **envp)
{
	pidfd->p1 = fork();
	if (pidfd->p1 == 0)
		pid1_cmd(arg, pidfd, err, envp);
	pidfd->p2 = fork();
	if (pidfd->p2 == 0)
		pid2_cmd(arg, pidfd, err, envp);
}
