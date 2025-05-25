/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:57:49 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 20:42:32 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pidfd	*in_file_open(t_arg *arg, t_error *err, char **envp)
{
	pid_t	pid;
	int		in_file;

	if (err->in_file == false)
		return (-1);
	in_file = open(arg->c_arg[0], O_RDONLY);
	return (in_file);
}

static t_pidfd	*out_file_open(t_arg *arg, t_error *err, char **envp)
{
	pid_t	pid;
	int		out_file;

	if (err->out_file == false)
		return (-1);
	out_file = open(arg->c_arg[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (out_file);
}

void	file_open(t_arg *arg, t_pidfd *pidfd, t_error *err, char **envp)
{
	pidfd->in_fd = in_file_open(arg, err, envp);
	pidfd->out_fd = out_file_open(arg, err, envp);
}
