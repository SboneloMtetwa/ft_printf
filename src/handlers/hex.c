/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:51:49 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 09:01:29 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "helpers.h"

inline static intmax_t	s_handle_mod(t_list_param param, va_list list)
{
	intmax_t		n;

	if (param.modifier == L)
		n = va_arg(list, long);
	else if (param.modifier == LL)
		n = va_arg(list, long long);
	else if (param.modifier == J)
		n = va_arg(list, intmax_t);
	else if (param.modifier == Z)
		n = va_arg(list, ssize_t);
	else
		n = va_arg(list, int);
	if (param.modifier == HH)
		n = (char)n;
	else if (param.modifier == H)
		n = (short)n;
	return (n);
}

inline static int		s_handle(t_list_param param, va_list list)
{
	char			*str;
	int				count;
	char			sign;
	intmax_t		n;

	count = 0;
	n = s_handle_mod(param, list);
	param.value = &n;
	if (param.flags & FT_FLAG_PLUS)
		sign = '+';
	else if (param.flags & FT_FLAG_SPACE)
		sign = ' ';
	else
		sign = 0;
	if (param.precision == 0 && n == 0)
		str = NULL;
	else
		str = ft_itoa(n, param, sign);
	count += ft_write_chunk(str, str != NULL, ft_strlen(str, INT_MAX), param);
	return (count);
}

static inline intmax_t	handle_mod(t_list_param param, va_list list)
{
	intmax_t n;

	if (param.modifier == L)
		n = va_arg(list, unsigned long);
	else if (param.modifier == LL)
		n = va_arg(list, unsigned long long);
	else if (param.modifier == J)
		n = va_arg(list, uintmax_t);
	else if (param.modifier == Z)
		n = va_arg(list, size_t);
	else
		n = va_arg(list, unsigned int);
	if (param.modifier == HH)
		n = (unsigned char)n;
	else if (param.modifier == H)
		n = (unsigned short)n;
	return (n);
}

int						ft_for_hex(t_list_param param, va_list list)
{
	uintmax_t		n;
	char			*s;
	int				count;
	int				base;
	int				size;

	if (param.conversion == 'd')
		return (s_handle(param, list));
	base = ft_get_base(param.conversion);
	count = 0;
	size = 0;
	if (param.flags & FT_FLAG_HASH || param.conversion == 'p')
		size = (param.conversion == 'o' ? 1 : 2);
	n = handle_mod(param, list);
	param.value = &n;
	if ((param.precision == 0 && n == 0) || (n == 0 && param.conversion == 'o'
				&& (param.flags & FT_FLAG_HASH)))
		s = NULL;
	else
		s = ft_uitoa(n, base, (param.conversion == 'X' ? "0123456789ABCDEF" :
				"0123456789abcdef"), ft_max(param.precision, ((param.flags &
				FT_FLAG_ZERO) && !(param.flags & FT_FLAG_MINUS) ?
				param.width - size : 0)));
	count += ft_write_chunk(s, s != NULL, ft_strlen(s, INT_MAX), param);
	return (count);
}
