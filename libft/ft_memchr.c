/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:50:00 by ebresser          #+#    #+#             */
/*   Updated: 2020/02/14 09:04:36 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char *)s;
	i = 0;
	while (i < n && i < ft_strlen(s) + 1)
	{
		if (ps[i] == (unsigned char)c)
			return (ps + i);
		else
			i++;
	}
	return (NULL);
}
