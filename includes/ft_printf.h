/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:44:43 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 11:28:27 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# define FT_FLAG_NONE 0
# define FT_FLAG_HASH 1
# define FT_FLAG_ZERO 2
# define FT_FLAG_MINUS 4
# define FT_FLAG_PLUS 8
# define FT_FLAG_SPACE 16
# define FT_FLAG_APOSTROPHE 32

typedef struct	s_list_string
{
	const char	*str;
	size_t		length;
}				t_list_string;

typedef enum	e_list_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6
}				t_list_modifier;

typedef struct	s_list_argument
{
	size_t			position;
	size_t			length;
	t_list_string	str;
}				t_list_argument;

typedef struct	s_list_param
{
	t_list_string	str;
	int				access;
	int				flags;
	unsigned int	width;
	int				width_access;
	int				precision;
	t_list_modifier	modifier;
	char			conversion;
	int				error;
	void			*value;
}				t_list_param;

/*
** Used when parsing formats and when doing the final substitution.
*/

typedef struct	s_list_handle
{
	char			conversion;
	int				(*handle)(t_list_param, va_list);
}				t_list_handle;

/*
** Handlers
*/

int				ft_for_percent(t_list_param param, va_list list);
int				ft_for_char(t_list_param param, va_list list);
int				ft_for_string(t_list_param param, va_list list);
int				ft_for_hex(t_list_param param, va_list list);

int				ft_write_chunk(const char *str, int free, size_t len,
					t_list_param param);

/*
** Core
*/

int				ft_printf(const char *format, ...);

int				ft_parse_format(const char *str, va_list list);
int				ft_transform(t_list_param param, va_list list);

int				ft_write(const char *str, const size_t len);
int				ft_repeat(const char c, size_t len);

int				ft_is_conversion(const char c);
int				ft_is_modifier(const char c);
int				ft_is_flag(const char c);
int				ft_is_valid(const char c);
t_list_param	ft_param(const char *str, const size_t len);
t_list_string	ft_string(const char *str, size_t len);
t_list_param	ft_get_param(const char *str, size_t len);

#endif
