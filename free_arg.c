/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:38:53 by rohta             #+#    #+#             */
/*   Updated: 2025/05/25 22:28:44 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(t_arg *arg)
{
	size_t	i;

	i = 0;
	while (arg->s_arg[i])
	{
		free(arg->s_arg);
		i++;
	}
	free(arg->s_arg);
	i = 0;
	while (arg->c_arg[i])
	{
		free(arg->c_arg);
		i++;
	}
	free(arg->c_arg);
}

void	free_arg(char **arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
