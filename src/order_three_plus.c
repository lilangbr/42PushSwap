/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:52:24 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/29 19:32:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_depth(t_stack *stack, int b)
{
	int		pos;
	t_node	*aux;

	pos = 1;
	if (stack->top != NULL)
	{
		if (stack->top->normalized == b)
			return (pos);
		else
		{
			aux = stack->top;
			while (aux->next != NULL)
			{
				aux = aux->next;
				pos = pos + 1;
				if (aux->normalized == b)
					return (pos);
			}
			if (aux->normalized == b)
				return (pos + 1);
		}
	}
	else
		return (0);
	return (pos);
}

static void	depth_five(t_game *towers, int smaller_pos)
{
	if (smaller_pos == 3)
	{
		move(towers, RA);
		move(towers, RA);
	}
	else if (smaller_pos == 4)
	{
		move(towers, RRA);
		move(towers, RRA);
	}
	else if (smaller_pos == 5)
		move(towers, RRA);
}

static void	depth_four(t_game *towers, int smaller_pos)
{
	if (smaller_pos == 3)
	{
		move(towers, RRA);
		move(towers, RRA);
	}
	else if (smaller_pos == 4)
		move(towers, RRA);
}

void	order_three_plus(t_game *towers, int plus)
{
	int	smaller_pos;
	int	smaller;

	smaller = 0;
	while (plus > 0)
	{
		smaller_pos = find_depth(&towers->a, smaller);
		if (smaller_pos == 2)
			move(towers, RA);
		if (plus == 2)
			depth_five(towers, smaller_pos);
		else
			depth_four(towers, smaller_pos);
		move(towers, PB);
		plus = plus - 1;
		smaller = smaller + 1;
	}
	order_three(towers);
	move(towers, PA);
	move(towers, PA);
	free_stack(&towers->a);
	free_stack(&towers->b);
}
