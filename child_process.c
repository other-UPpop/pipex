/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:17:04 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 02:01:09 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_cmd(char *cmd, char **envp, t_arg arg)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		error_print_cmd(args[0]);
		free_args(args);
		free_args(arg.c_arg);
		free_args(arg.s_arg);
		exit(127);
	}
	execve(cmd_path, args, envp);
	perror("execve");
	free_args(args);
	return ;
}

void	pid1_cmd(t_arg arg, t_fd fd, int pipefd[2], char **envp)
{
	if (fd.get_fd < 0)
		exit(0);
	dup2(fd.get_fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd.get_fd);
	close(fd.out_fd);
	execve_cmd(arg.c_arg[1], envp, arg);
	free_args(arg.c_arg);
	free_args(arg.s_arg);
	exit(1);
}

void	pid2_cmd(t_arg arg, t_fd fd, int pipefd[2], char **envp)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd.out_fd, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd.get_fd);
	close(fd.out_fd);
	execve_cmd(arg.c_arg[2], envp, arg);
	free_args(arg.c_arg);
	free_args(arg.s_arg);
	exit(1);
}
