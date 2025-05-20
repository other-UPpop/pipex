/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:11:09 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 01:45:55 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sleep_var(t_arg arg, char **envp)
{
	size_t	i;

	i = 0;
	while (arg.c_arg[i])
	{
		if (ft_strnstr(arg.c_arg[i], "sleep", ft_strlen(arg.c_arg[i])))
			execve_cmd(arg.c_arg[i], envp, arg);
		i++;
	}
}

int	get_file_open(t_arg arg, char **envp)
{
	int		get_file;
	pid_t	pid;

	get_file = open(arg.c_arg[0], O_RDONLY);
	if (get_file < 0)
	{
		if (access(arg.c_arg[3], W_OK) != 0)
		{
			error_print_open2_file(arg);
			pid = fork();
			if (pid == 0)
				sleep_var(arg, envp);
			waitpid(pid, NULL, 0);
		}
		if (access(arg.c_arg[0], (F_OK) != 0))
			error_print_open1_file(arg);
		else
			error_print_open3_file(arg);
	}
	return (get_file);
}

int	out_file_open(t_arg arg, t_fd fd)
{
	int	get_file;

	get_file = open(arg.c_arg[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (get_file < 0)
	{
		close(fd.get_fd);
		free_args(arg.c_arg);
		free_args(arg.s_arg);
		exit (1);
	}
	return (get_file);
}
