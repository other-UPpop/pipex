/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:38:43 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 21:50:22 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pirnt_notsuch(char *str, t_error *err)
{
	char	*str1;
	char	*str2;

	str1 = "bash: ";
	str2 = ": No such file or directory\n";
	write(STDERR_FILENO, str1, ft_strlen(str1));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, str2, ft_strlen(str2));
	err->log++;
}

void	error_pirnt_permission(char *str, t_error *err)
{
	char	*str1;
	char	*str2;

	str1 = "bash: ";
	str2 = ": Permission denied\n";
	write(STDERR_FILENO, str1, ft_strlen(str1));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, str2, ft_strlen(str2));
	err->log++;
}

void	error_print_cmd(char *arg, t_error *err)
{
	char	*e_str2;

	e_str2 = ": command not found\n";
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, e_str2, ft_strlen(e_str2));
	err->log++;
}