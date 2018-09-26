/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:02:40 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 08:17:40 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

int				ft_isdigit(int c);
void			*ft_memalloc(size_t size);
char			*ft_strjoin(char *a, char *b);
int				ft_atoi(const char *str, int allow_neg, int *result, size_t *i);
char			*ft_itoa(intmax_t n, t_list_param param, char sign);
char			*ft_uitoa(uintmax_t n, unsigned int base, const char *digits,
					size_t precision);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s, const size_t max);

int				ft_max(int a, int b);
int				ft_get_base(char c);
#endif
