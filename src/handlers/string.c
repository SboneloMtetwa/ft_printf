/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:30:26 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 09:00:37 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "helpers.h"

int					ft_for_string(t_list_param param, va_list list)
{
	char	*str;
	size_t	len;
	int		count;

	count = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str, INT_MAX);
	if (param.precision == -1)
		param.precision = INT_MAX;
	if (param.precision > (int)len)
		param.precision = len;
	count += ft_write_chunk(str, 0, param.precision, param);
	return (count);
}

inline static void	set_prefix(t_list_param param, int *rem, char **prefix)
{
	if ((!(param.flags & FT_FLAG_HASH) ||
			(param.value && *(uintmax_t *)param.value == 0))
			&& !((param.flags & FT_FLAG_HASH) && param.conversion == 'o')
			&& !(param.conversion == 'p'))
		return ;
	if (param.conversion == 'x' || param.conversion == 'X' ||
			param.conversion == 'p')
	{
		*rem = 2;
		*prefix = (param.conversion == 'X' ? "0X" : "0x");
	}
	if (param.conversion == 'o')
	{
		*rem = 1;
		*prefix = "0";
	}
}

int					ft_write_chunk(const char *str, int f, size_t len,
						t_list_param param)
{
	int		count;
	int		rem;
	char	*prefix;
	char	p;

	count = 0;
	rem = 0;
	p = (param.conversion != 'd' && param.flags & FT_FLAG_ZERO ? '0' : ' ');
	set_prefix(param, &rem, &prefix);
	if (param.conversion == 'o' && str && str[0] == '0')
		rem = 0;
	param.width -= rem;
	if (!(param.flags & FT_FLAG_MINUS) && param.width > len)
		count += ft_repeat(p, param.width - len);
	if (rem)
		count += ft_write(prefix, rem);
	count += ft_write(str, len);
	if ((param.flags & FT_FLAG_MINUS) && param.width > len)
		count += ft_repeat(' ', param.width - len);
	if (f)
		free((void *)str);
	return (count);
}
