/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:26:36 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 10:15:18 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern inline void		*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		((unsigned char *)ptr)[size] = (unsigned char)0;
	}
	return (ptr);
}

extern inline char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

extern inline size_t	ft_strlen(const char *s, const size_t max)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < max)
		i++;
	return (i);
}

extern inline int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
