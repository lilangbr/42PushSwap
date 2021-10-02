/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:25:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cut(int number, int out)
{
	int		div;
	int		mod;
	char	c;

	div = number / 10;
	mod = number % 10;
	if (div != 0)
		cut(div, out);
	c = '0' + mod;
	ft_putchar_fd(c, out);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n != 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (n == -2147483648)
			{
				n = (-1) * (n / 10);
				cut(n, fd);
				ft_putchar_fd('8', fd);
			}
			else
			{
				n = -n;
				cut(n, fd);
			}
		}
		else
			cut(n, fd);
	}
	else
		ft_putchar_fd('0', fd);
}
