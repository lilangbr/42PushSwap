/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:02:23 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:28:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **array, int i)
{
	while (i > -1)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static char	*bypass(char *s, char c)
{
	if (*s == c)
	{
		while (*(s + 1) == c)
			s++;
		return (s + 1);
	}
	else
		return (s);
}

static char	**fill(char **splitted, size_t size, const char *s, char c)
{
	size_t	i;
	size_t	begin;
	size_t	end;

	i = 0;
	begin = 0;
	while (i < size - 1)
	{
		while (s[begin] == c)
			begin++;
		end = begin;
		while (s[end] != c && s[end] != '\0')
			end++;
		splitted[i] = (char *)malloc((end - begin + 1) * sizeof(char));
		if (!(splitted[i]))
		{
			freeall(splitted, i - 1);
			return (NULL);
		}
		ft_strlcpy(splitted[i], &s[begin], end - begin + 1);
		begin = end;
		i++;
	}
	splitted[size - 1] = NULL;
	return (splitted);
}

static int	wcount(const char *s, char c)
{
	int		wc;
	char	*str;

	wc = 0;
	str = (char *)s;
	str = bypass(str, c);
	while (*str)
	{
		while (*str != c && *str != '\0')
			str++;
		if (*str == c)
		{
			str = bypass(str, c);
			wc++;
		}
		else if (*str == '\0')
			wc++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		wc;

	if (!s)
		return (NULL);
	if (*s == '\0')
		wc = 0;
	else if (c == '\0')
		wc = 1;
	else
		wc = wcount(s, c);
	splitted = (char **)malloc((wc + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	if (*s == '\0')
		splitted[0] = NULL;
	else if (c == '\0')
	{
		splitted[0] = ft_strdup(s);
		splitted[1] = NULL;
	}
	else
		splitted = fill(splitted, wc + 1, s, c);
	return (splitted);
}
