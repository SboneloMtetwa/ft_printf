/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:19:37 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 09:30:57 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;

	va_start(list, format);
	result = ft_parse_format(format, list);
	va_end(list);
	return (result);
}
