/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:50:13 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 11:07:47 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_transform(t_list_param param, va_list list)
{
	static t_list_handle	(handle[12]) = {
		{ .conversion = 's', .handle = ft_for_string },
		{ .conversion = 'S', .handle = ft_for_string },
		{ .conversion = 'c', .handle = ft_for_char },
		{ .conversion = 'C', .handle = ft_for_char },
		{ .conversion = '%', .handle = ft_for_percent },
		{ .conversion = 'd', .handle = ft_for_hex },
		{ .conversion = 'x', .handle = ft_for_hex },
		{ .conversion = 'X', .handle = ft_for_hex },
		{ .conversion = 'p', .handle = ft_for_hex },
		{ .conversion = 'u', .handle = ft_for_hex },
		{ .conversion = 'U', .handle = ft_for_hex },
		{ .conversion = 'o', .handle = ft_for_hex }
	};
	int						i;

	if (param.error)
		return (0);
	i = -1;
	while (++i < 12)
		if (param.conversion == handle[i].conversion)
			return (handle[i].handle(param, list));
	return (0);
}
