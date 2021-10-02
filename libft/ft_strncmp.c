/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:16:12 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:36:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	diff(const char *a, const char *b, int i)
{
	unsigned char	ua;
	unsigned char	ub;

	ua = (unsigned char)a[i];
	ub = (unsigned char)b[i];
	return (ua - ub);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		compare;

	i = 0;
	compare = 1;
	while (compare)
	{
		if (i == n)
			return (0);
		else if (s1[i] == '\0' || s2[i] == '\0')
			compare = 0;
		else if (s1[i] != s2[i])
			compare = 0;
		else
			i++;
	}
	return (diff(s1, s2, i));
}
