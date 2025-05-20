/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:17:04 by rohta             #+#    #+#             */
/*   Updated: 2025/05/20 23:24:58 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_print(char *arg)
{
	char	*e_str1;
	char	*e_str2;

	e_str1 = "bash: ";
	e_str2 = ": command not found\n";
	write(STDERR_FILENO, e_str1, ft_strlen(e_str1));
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}

void	execve_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		error_print(args[0]);
		free_args(args);
		exit (1);
	}
	execve(cmd_path, args, envp);
	perror("execve");
	free_args(args);
	return ;
}

void	pid1_cmd(t_arg arg, t_fd fd, int pipefd[2], char **envp)
{
	dup2(fd.get_fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd.get_fd);
	close(fd.out_fd);
	execve_cmd(arg.c_arg[1], envp);
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
	execve_cmd(arg.c_arg[2], envp);
	free_args(arg.c_arg);
	free_args(arg.s_arg);
	exit(1);
}
