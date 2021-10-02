/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:07:16 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 23:09:30 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_int_number(int argc, char **argv)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (c < argc)
	{
		if (argv[c][i] == '-' && argv[c][i + 1] != '\0')
			i++;
		while (argv[c][i] != '\0')
		{
			if (ft_isdigit(argv[c][i]))
				i++;
			else
				error();
		}
		i = 0;
		c++;
	}
}

static double	pick_value(char *thisarg)
{
	int		i;
	int		isnegative;
	double	value;

	i = 0;
	isnegative = 0;
	value = 0;
	if (thisarg[i] == '-')
	{
		isnegative = 1;
		i++;
	}
	while (thisarg[i] != '\0')
	{
		value = value * 10 + (thisarg[i] - '0');
		i++;
	}
	if (isnegative)
		value = -value;
	return (value);
}

static void	is_out_of_limit(int argc, char **argv)
{
	double	test;
	int		c;

	c = 0;
	while (c < argc)
	{
		if (ft_strlen(argv[c]) > 11)
			error();
		test = pick_value(argv[c]);
		if ((test > 0 && test > INT_MAX) || (test < 0 && test < INT_MIN))
			error();
		c++;
	}
}

static void	is_duplicated(int argc, char **argv)
{
	int	element;
	int	c;
	int	ci;

	c = 0;
	while (c < argc)
	{
		element = ft_atoi(argv[c]);
		ci = 0;
		while (ci < argc)
		{
			if (element == ft_atoi(argv[ci]) && ci != c)
				error();
			ci++;
		}
		c++;
	}
}

void	validate_args(int argc, char **argv)
{
	is_int_number(argc, argv);
	is_out_of_limit(argc, argv);
	is_duplicated(argc, argv);
}
