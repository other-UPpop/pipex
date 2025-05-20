/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:11:09 by rohta             #+#    #+#             */
/*   Updated: 2025/05/20 16:36:41 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_print_file(t_arg arg)
{
	char	*e_str1;
	char	*e_str2;

	e_str1 = "bash: ";
	e_str2 = ": No such file or directory\n";
	write(STDERR_FILENO, e_str1, ft_strlen(e_str1));
	write(STDERR_FILENO, arg.s_arg[0], ft_strlen(arg.s_arg[0]));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}

int	get_file_open(t_arg arg)
{
	int	get_file;

	get_file = open(arg.c_arg[0], O_RDONLY);
	if (get_file < 0)
	{
		error_print_file(arg);
		free_args(arg.c_arg);
		free_args(arg.s_arg);
		exit (0);
	}
	return (get_file);
}

int	out_file_open(t_arg arg, t_fd fd)
{
	int	get_file;

	get_file = open(arg.c_arg[3], O_WRONLY | O_CREAT | O_TRUNC, 666);
	if (get_file < 0)
	{
		perror("outfile");
		close(fd.get_fd);
		free_args(arg.c_arg);
		free_args(arg.s_arg);
		exit (1);
	}
	return (get_file);
}
