/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:07:37 by rohta             #+#    #+#             */
/*   Updated: 2025/05/21 18:01:17 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	get_total_len(int argc, char **argv)
{
	size_t	total;
	int		i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			exit (0);
		total += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (total);
}

static char	*get_arg(int argc, char **argv, char *sp_str)
{
	size_t	offset;
	size_t	len;
	int		i;

	offset = 0;
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (offset != 0)
			sp_str[offset++] = ' ';
		ft_memcpy(sp_str + offset, argv[i], len);
		offset += len;
		i++;
	}
	sp_str[offset] = '\0';
	return (sp_str);
}

static char	**div_str(char	**aft_str)
{
	size_t	count;
	char	**cmd;

	count = count_cmds(aft_str);
	cmd = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!cmd)
		return (NULL);
	put_cmd(cmd, aft_str);
	return (cmd);
}

void	get_arg_ck(int argc, char **argv, t_arg *arg)
{
	size_t	len;
	char	*sp_str;

	len = get_total_len(argc, argv);
	sp_str = (char *)malloc(len + 1);
	if (!sp_str)
		return ;
	sp_str = get_arg(argc, argv, sp_str);
	if (sp_str)
		arg->s_arg = ft_split(sp_str, ' ');
	if (arg->s_arg)
		arg->c_arg = div_str(arg->s_arg);
	free(sp_str);
}
