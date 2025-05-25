/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:57:49 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 22:48:45 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_open(t_arg *arg, t_pidfd *pidfd)
{
	pidfd->in_fd = open(arg->c_arg[0], O_RDONLY);
	pidfd->out_fd = open(arg->c_arg[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
}
