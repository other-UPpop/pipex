/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:59:47 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 01:35:32 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_arg *arg, t_pidfd *pidfd, t_error *err)
{
	arg->s_arg = NULL;
	arg->c_arg = NULL;
	pidfd->in_fd = -1;
	pidfd->out_fd = -1;
	err->in_file = true;
	err->out_file = true;
	err->cmd1 = true;
	err->cmd2 = true;
	err->log = 0;
	err->return_num = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_arg	arg;
	t_pidfd	pidfd;
	t_error	err;

	init_pipex(&arg, &pidfd, &err);
	arg_check(ac, av, &err);
	get_arg(ac, av, &arg);
	file_open(&arg, &pidfd, &err);
	pipex(&arg, &pidfd, &err, envp);
	return (err.return_num);
}
