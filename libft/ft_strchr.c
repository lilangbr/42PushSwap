/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:09:20 by ebresser          #+#    #+#             */
/*   Updated: 2020/02/14 10:22:06 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	int		i;

	ps = (char *)s;
	i = 0;
	while (ps[i] != '\0')
	{
		if (ps[i] == (char)c)
			return (ps + i);
		i++;
	}
	if ((char)c == '\0' && ps[i] == '\0')
		return (ps + i);
	return (NULL);
}
