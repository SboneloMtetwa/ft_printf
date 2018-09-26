/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:28:28 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/17 08:27:18 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_for_char(t_list_param param, va_list list)
{
	int		count;
	int		c;
	char	p;

	p = (param.flags & FT_FLAG_ZERO ? '0' : ' ');
	count = 0;
	c = va_arg(list, int);
	if ((param.flags & FT_FLAG_MINUS) == 0 && param.width > 1)
		count += ft_repeat(p, param.width - 1);
	count += ft_write((char *)&c, 1);
	if ((param.flags & FT_FLAG_MINUS) != 0 && param.width > 1)
		count += ft_repeat(' ', param.width - 1);
	return (count);
}
