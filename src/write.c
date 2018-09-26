/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:32:08 by smtetwa           #+#    #+#             */
/*   Updated: 2018/08/19 09:56:25 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_write(const char *str, const size_t len)
{
	write(1, str, len);
	return (len);
}

int			ft_repeat(const char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_write(&c, 1);
		i++;
	}
	return (i);
}
