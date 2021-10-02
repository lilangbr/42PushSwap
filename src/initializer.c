/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:42:15 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 22:42:29 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_game *towers)
{
	towers->a.top = NULL;
	towers->b.top = NULL;
}

void	fill_a_stack(int argc, char **argv, t_stack *a)
{
	t_node	*new;
	int		i;

	i = argc - 1;
	while (i >= 0)
	{
		new = new_node(ft_atoi(argv[i]), -1);
		push_one(a, new);
		i--;
	}
}
