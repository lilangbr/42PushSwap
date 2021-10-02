/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:38:02 by ebresser          #+#    #+#             */
/*   Updated: 2020/02/12 19:31:16 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	void			*p3;
	size_t			i;

	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		if (p2[i] == (unsigned char)c)
		{
			p3 = (void *)(&p2[i + 1]);
			return (p3);
		}
		i++;
	}
	return (NULL);
}
