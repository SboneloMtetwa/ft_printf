/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:37:20 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 09:58:09 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"
#include "helpers.h"

int			for_access(t_list_param *param, const char *str, size_t *i)
{
	int access;
	int t;

	t = *i;
	if (!ft_isdigit(str[*i]))
		return (0);
	if (ft_atoi(str, 0, &access, i) || str[*i] != '$')
	{
		*i = t;
		return (0);
	}
	(*i)++;
	param->access = access;
	return (0);
}

int			for_flags(t_list_param *param, const char *str, size_t *i)
{
	char c;

	while (*i < param->str.length)
	{
		c = str[*i];
		if (ft_is_flag(c))
		{
			if (c == '#')
				param->flags |= FT_FLAG_HASH;
			else if (c == '0')
				param->flags |= FT_FLAG_ZERO;
			else if (c == '-')
				param->flags |= FT_FLAG_MINUS;
			else if (c == '+')
				param->flags |= FT_FLAG_PLUS;
			else if (c == ' ')
				param->flags |= FT_FLAG_SPACE;
			else if (c == '\'')
				param->flags |= FT_FLAG_APOSTROPHE;
		}
		else
			return (0);
		(*i)++;
	}
	return (1);
}

int			for_width(t_list_param *param, const char *str, size_t *i)
{
	int width;
	int is_pos;

	if ((is_pos = (str[*i] == '*')))
		(*i)++;
	if (ft_atoi(str, 0, &width, i) && !is_pos)
		return (1);
	if (is_pos)
	{
		if (str[*i] == '$')
			(*i)++;
		else
			return (1);
		param->width_access = width;
	}
	else
		param->width = width;
	return (0);
}

int			for_precision(t_list_param *p, const char *str, size_t *i)
{
	int precision;

	p->precision = -1;
	if (str[*i] != '.')
		return (0);
	p->precision = 0;
	(*i)++;
	if (ft_atoi(str, 0, &precision, i))
		return (1);
	p->precision = precision;
	return (0);
}

int			for_modifier(t_list_param *p, const char *str, size_t *i)
{
	t_list_modifier	m;

	m = NONE;
	if (!ft_is_modifier(str[*i]))
		return (0);
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l' && ++(*i))
			m = LL;
		else
			m = L;
	}
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h' && ++(*i))
			m = HH;
		else
			m = H;
	}
	else if (str[*i] == 'j')
		m = J;
	else if (str[*i] == 'z')
		m = Z;
	p->modifier = m;
	return ((*i)++ & 0);
}
