/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:18:48 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 11:10:38 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "helpers.h"

inline extern int			ft_is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

inline extern int			ft_is_modifier(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

inline extern int			ft_is_flag(const char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

inline extern int			ft_is_precision(const char c)
{
	return (ft_strchr("$*.", c) != NULL);
}

inline int					ft_is_valid(const char c)
{
	return (ft_is_conversion(c) || ft_is_modifier(c) || ft_is_flag(c) ||
			ft_isdigit(c) || ft_is_precision(c));
}
