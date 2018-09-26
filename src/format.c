/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:35:56 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 11:13:40 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						get_argument(const char *str, size_t len, int is_valid,
							va_list list)
{
	if (*str == '%' && is_valid)
		return (ft_transform(ft_get_param(str, len), list));
	else
		return (ft_write(str, len));
}

static int				parse_inner(const char *str, size_t *i, int *valid)
{
	if (!str[*i])
		return (1);
	while (str[*i] && ft_is_valid(str[*i]) && !ft_is_conversion(str[*i]))
		(*i)++;
	if ((*valid = str[*i] && ft_is_valid(str[*i])))
		(*i)++;
	else
		return (1);
	return (0);
}

/*
** Parse a format string and prints stuff
*/

int						ft_parse_format(const char *str, va_list list)
{
	size_t			i;
	size_t			start;
	int				valid;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		start = i;
		valid = 0;
		if (str[i] == '%')
		{
			i++;
			if (parse_inner(str, &i, &valid))
				continue;
		}
		else
			while (str[i] && str[i] != '%')
				i++;
		count += get_argument(str + start, i - start, valid, list);
	}
	return (count);
}

inline	t_list_param	ft_param(const char *str, size_t len)
{
	t_list_param	param;

	param = (t_list_param) {
		.str = (t_list_string){ .str = str, .length = len },
			.access = 0,
			.flags = 0,
			.width = 0,
			.width_access = 0,
			.precision = 0,
			.modifier = NONE,
			.conversion = 0,
			.error = 0
	};
	return (param);
}

inline	t_list_string	ft_string(const char *str, size_t len)
{
	return ((t_list_string) {
			.str = str,
			.length = len
			});
}
