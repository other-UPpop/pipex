/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:46:43 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 21:51:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_check(int ac, char **av, t_error *err)
{
	if (ac < 5 | ac > 5)
		exit (0);
	if (access(av[1], (F_OK | R_OK)) != 0)
	{
		err->in_file = false;
		if (access(av[1], (F_OK)) != 0)
			error_print_notsuch(av[1], err);
		else if (access(av[1], (R_OK)) != 0)
			errro_print_permission(av[1], err);
	}
	if (access(av[4], (W_OK)) != 0)
	{
		error_print_permission(av[4], err);
		err->out_file = false;
		err->return_num = 1;
	}
}