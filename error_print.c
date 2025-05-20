/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:28:36 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 00:11:47 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_print_open3_file(t_arg arg)
{
	char	*e_str1;
	char	*e_str2;

	e_str1 = "bash: ";
	e_str2 = ": Permission denied\n";
	write(STDERR_FILENO, e_str1, ft_strlen(e_str1));
	write(STDERR_FILENO, arg.c_arg[0], ft_strlen(arg.c_arg[0]));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}

void	error_print_open2_file(t_arg arg)
{
	char	*e_str1;
	char	*e_str2;

	e_str1 = "bash: ";
	e_str2 = ": Permission denied\n";
	write(STDERR_FILENO, e_str1, ft_strlen(e_str1));
	write(STDERR_FILENO, arg.c_arg[3], ft_strlen(arg.c_arg[3]));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}

void	error_print_open1_file(t_arg arg)
{
	char	*e_str1;
	char	*e_str2;

	e_str1 = "bash: ";
	e_str2 = ": No such file or directory\n";
	write(STDERR_FILENO, e_str1, ft_strlen(e_str1));
	write(STDERR_FILENO, arg.s_arg[0], ft_strlen(arg.s_arg[0]));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}

void	error_print_cmd(char *arg)
{
	char	*e_str2;

	e_str2 = ": command not found\n";
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
}
