/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:10:21 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 21:07:12 by rohta            ###   ########.fr       */
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

typedef struct s_pidfd
{
	int		in_fd;
	int		out_fd;
	pid_t	p1;
	pid_t	p2;
	int		pipefd[2];
}	t_pidfd;

typedef struct s_pid
{
	pid_t	p1;
	pid_t	p2;
	int		pipefd[2];
}	t_pid;

typedef struct s_error
{
	bool	in_file;
	bool	out_file;
	bool	cmd1;
	bool	cmd2;
	int		log;
	int		return_num;
}	t_error;

typedef struct s_pipex
{
	t_arg	arg;
	t_pidfd	fd;
	t_pid	pid;
	t_error	error;
}	t_pipex;

#endif
