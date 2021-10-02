/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:04:03 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:36:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + ft_strlen(needle) < len + 1)
	{
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
