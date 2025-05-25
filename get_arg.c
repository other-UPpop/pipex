/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:56:59 by rohta             #+#    #+#             */
/*   Updated: 2025/05/26 00:00:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_total_len(int ac, char **av)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			exit(0);
		total += ft_strlen(av[i]) + 1;
		i++;
	}
	return (total);
}

static char	*get_total_arg(int ac, char **av, char *str)
{
	int	offset;
	int	len;
	int	i;

	offset = 0;
	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (offset != 0)
			str[offset++] = ' ';
		ft_memcpy(str + offset, av[i], len);
		offset += len;
		i++;
	}
	str[offset] = '\0';
	return (str);
}

void	get_arg(int ac, char **av, t_arg *arg)
{
	char	*str;
	int		len;

	len = get_total_len(ac, av);
	str = (char *)malloc(len + 1);
	if (!str)
		return ;
	str = get_total_arg(ac, av, str);
	if (str)
		arg->s_arg = ft_split(str, ' ');
	if (arg->s_arg)
		arg->c_arg = div_str(arg->s_arg);
	free(str);
}
