/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:53:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/08/19 11:07:24 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_for_percent(t_list_param param, va_list list)
{
	int		count;
	char	p;

	(void)list;
	p = (param.flags & FT_FLAG_ZERO ? '0' : ' ');
	count = 0;
	if ((param.flags & FT_FLAG_MINUS) == 0 && param.width > 1)
		count += ft_repeat(p, param.width - 1);
	count += ft_write("%", 1);
	if ((param.flags & FT_FLAG_MINUS) != 0 && param.width > 1)
		count += ft_repeat(' ', param.width - 1);
	return (count);
}
