/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 10:24:34 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 10:13:05 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

int						for_conversion(t_list_param *p,
		const char *str, size_t *i)
{
	if (ft_is_conversion(str[*i]))
	{
		p->conversion = str[*i];
		(*i)++;
		return (0);
	}
	return (1);
}

static	t_list_param	big_conversions(t_list_param param)
{
	if (param.conversion == 'D' || param.conversion == 'S' ||
			param.conversion == 'C' || param.conversion == 'O' ||
			param.conversion == 'U')
		param.modifier = L;
	if (param.conversion == 'D')
		param.conversion = 'd';
	if (param.conversion == 'S')
		param.conversion = 's';
	if (param.conversion == 'C')
		param.conversion = 'c';
	if (param.conversion == 'O')
		param.conversion = 'o';
	if (param.conversion == 'U')
		param.conversion = 'u';
	return (param);
}

t_list_param			ft_get_param(const char *str, size_t len)
{
	static int		(*handle[6])(t_list_param *, const char *, size_t *) = {
						for_access, for_flags, for_width,
						for_precision, for_modifier, for_conversion};
	t_list_param	param;
	size_t			i;
	size_t			pos;

	i = 0;
	pos = 0;
	param = ft_param(str, len);
	while (i < 6)
	{
		if ((*handle[i])(&param, str + 1, &pos))
		{
			param.error = 1;
			break ;
		}
		i++;
	}
	if (param.conversion == 'i')
		param.conversion = 'd';
	if (param.conversion == 'p')
		param.modifier = LL;
	return (big_conversions(param));
}
