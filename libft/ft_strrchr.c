/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:28:31 by ebresser          #+#    #+#             */
/*   Updated: 2020/02/14 11:20:34 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	int		i;
	int		last;

	ps = (char *)s;
	i = 0;
	last = -1;
	while (ps[i] != '\0')
	{
		if (ps[i] == (char)c)
			last = i;
		i++;
	}
	if ((char)c == '\0' && ps[i] == '\0')
		last = i;
	if (last != -1)
		return (ps + last);
	else
		return (NULL);
}
