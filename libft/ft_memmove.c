/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:16:04 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:24:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*cpy_inv(unsigned char *a, unsigned char *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		a[len - 1 - i] = b[len - 1 - i];
		i++;
	}
	return (a);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else
	{
		if (dst > src)
			cpy_inv(pdst, psrc, len);
		else
			ft_memcpy(pdst, psrc, len);
		return (dst);
	}
}
