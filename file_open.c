/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:57:49 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 00:21:35 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_open(t_arg *arg, t_pidfd *pidfd, t_error *err)
{
	if (err->in_file == true)
		pidfd->in_fd = open(arg->c_arg[0], O_RDONLY);
	if (err->out_file == true)
		pidfd->out_fd = open(arg->c_arg[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
}
