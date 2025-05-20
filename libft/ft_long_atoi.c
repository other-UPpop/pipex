/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:09:07 by rohta             #+#    #+#             */
/*   Updated: 2024/11/13 15:12:55 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(const char **str)
{
	int		sign;
	size_t	i;

	sign = 0;
	i = 0;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign++;
		i++;
		(*str)++;
	}
	if (i > 1)
		return (0);
	if (sign)
		return (-1);
	return (1);
}

static int	ft_isover_max(long num, const char *str)
{
	if (num > LONG_MAX / 10)
		return (1);
	if (num == LONG_MAX / 10)
		if (ft_strncmp(str, "7", 1) > 0)
			return (1);
	return (0);
}

static int	ft_isover_min(long num, const char *str)
{
	num *= -1;
	if (num < LONG_MIN / 10)
		return (1);
	if (num == LONG_MIN / 10)
		if (ft_strncmp(str, "8", 1) >= 0)
			return (1);
	return (0);
}

long	ft_long_atoi(const char *str)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign *= ft_issign(&str);
	while (*str >= '0' && *str <= '9')
	{
		if (sign == -1)
			if (ft_isover_min(num, str) == 1)
				return ((long)LONG_MIN);
		if (ft_isover_max(num, str) == 1)
			return ((long)LONG_MAX);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return ((long)num * sign);
}
