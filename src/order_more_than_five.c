/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more_than_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:02:47 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/29 19:32:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	step_flow(t_game *towers, int t_size_a, int step)
{
	int	count;

	count = 0;
	while (count < t_size_a)
	{
		if (((towers->a.top->normalized >> step) & 1) == 0)
			move(towers, PB);
		else
			move(towers, RA);
		count = count + 1;
	}
	while (!(is_empty(&towers->b)))
		move(towers, PA);
}

void	order_more_than_five(t_game *towers, int t_size_a)
{
	int	total_steps;
	int	step;

	if (towers->a.top == NULL)
		return ;
	total_steps = get_binary_digits(get_bigger(&towers->a));
	step = 0;
	while (step < total_steps)
	{
		step_flow(towers, t_size_a, step);
		if (is_ordered(&towers->a))
			return ;
		step = step + 1;
	}
	free_stack(&towers->a);
	free_stack(&towers->b);
}
