/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number_sub2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:16:18 by rohta             #+#    #+#             */
/*   Updated: 2024/11/13 15:41:14 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_minus_tmp(t_params *params, size_t *conv_len)
{
	char	*minus_str;

	minus_str = NULL;
	minus_str = ft_substr(params->converted, 1, (size_t)conv_len);
	free(params->converted);
	params->converted = minus_str;
}
