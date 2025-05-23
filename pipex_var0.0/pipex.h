/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:10:21 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 03:33:31 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_arg
{
	char	**s_arg;
	char	**c_arg;
}	t_arg;

typedef struct s_fd
{
	int		get_fd;
	int		out_fd;
}	t_fd;

typedef struct s_pid
{
	pid_t	p1;
	pid_t	p2;
}	t_pid;

int		main(int argc, char **argv, char **envp);
int		pipe_init(int pipefd[2]);
void	free_args(char **args);
void	parent_process_close(int pipefd[2], t_fd fd);
void	pid1_cmd(t_arg arg, t_fd fd, int pipefd[2], char **envp);
void	pid2_cmd(t_arg arg, t_fd fd, int pipefd[2], char **envp);
char	*get_cmd_path(char *arg, char **envp);
char	**put_cmd(char **cmd, char **aft_str);
size_t	count_cmds(char	**aft_str);
int		out_file_open(t_arg arg, t_fd fd, char **envp);
int		get_file_open(t_arg arg, char **envp);
void	get_arg_ck(int argc, char **argv, t_arg *arg);
char	*sleep_cmd(char **cmd, char **aft_str, size_t *i, size_t j);
char	*str_join(char **cmd, size_t j, size_t i, char **aft_str);
void	error_print_open1_file(t_arg arg);
void	error_print_open2_file(t_arg arg);
void	error_print_open3_file(t_arg arg);
void	error_print_cmd(char *arg);
void	execve_cmd(char *cmd, char **envp, t_arg arg);

#endif
