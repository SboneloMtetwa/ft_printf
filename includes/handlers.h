/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:18:32 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 10:21:03 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H
# include "ft_printf.h"

int				for_access(t_list_param *param, const char *str, size_t *i);
int				for_flags(t_list_param *param, const char *str, size_t *i);
int				for_width(t_list_param *param, const char *str, size_t *i);
int				for_precision(t_list_param *p, const char *str, size_t *i);
int				for_modifier(t_list_param *p, const char *str, size_t *i);
int				for_conversion(t_list_param *p, const char *str, size_t *i);
t_list_param	get_param(const char *str, size_t len);

#endif
