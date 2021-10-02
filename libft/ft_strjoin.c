/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:16:12 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:33:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copylen(char *scpy, const char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		scpy[i] = s[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	k;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	copylen(s, s1);
	k = ft_strlen(s1);
	copylen(&s[k], s2);
	k = k + ft_strlen(s2);
	s[k] = '\0';
	return (s);
}
