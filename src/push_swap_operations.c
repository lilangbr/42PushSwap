/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:29:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 23:06:15 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_game *towers, char which_stack)
{
	int	opa;
	int	opb;

	if (which_stack == 'a')
	{
		if (swap_one(&towers->a))
			ft_putendl_fd("sa", STDOUT_FILENO);
	}
	else if (which_stack == 'b')
	{
		if (swap_one(&towers->b))
			ft_putendl_fd("sb", STDOUT_FILENO);
	}
	else
	{
		opa = swap_one(&towers->a);
		opb = swap_one(&towers->b);
		if (opa || opb)
			ft_putendl_fd("ss", STDOUT_FILENO);
	}
}

void	push(t_game *towers, char which_stack)
{
	t_node	*new;

	if (which_stack == 'a')
	{
		if (towers->b.top != NULL)
		{
			new = new_node(towers->b.top->content, towers->b.top->normalized);
			pop_one(&towers->b);
			push_one(&towers->a, new);
			ft_putendl_fd("pa", STDOUT_FILENO);
		}
	}
	else
	{
		if (towers->a.top != NULL)
		{
			new = new_node(towers->a.top->content, towers->a.top->normalized);
			pop_one(&towers->a);
			push_one(&towers->b, new);
			ft_putendl_fd("pb", STDOUT_FILENO);
		}
	}
}

static void	aux_rotate(char which_stack, int operation)
{
	if (which_stack == 'a')
	{
		if (operation > 0)
			ft_putendl_fd("ra", STDOUT_FILENO);
		else if (operation < 0)
			ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else
	{
		if (operation > 0)
			ft_putendl_fd("rb", STDOUT_FILENO);
		else if (operation < 0)
			ft_putendl_fd("rrb", STDOUT_FILENO);
	}
}

void	rotate(t_game *towers, char which_stack, int (*f)(t_stack *stack))
{
	int	one_op;
	int	another_op;

	if (which_stack == 'a')
	{
		one_op = f(&towers->a);
		aux_rotate('a', one_op);
	}
	else if (which_stack == 'b')
	{
		one_op = f(&towers->b);
		aux_rotate('b', one_op);
	}
	else
	{
		one_op = f(&towers->a);
		another_op = f(&towers->b);
		if (one_op > 0 || another_op > 0)
			ft_putendl_fd("rr", STDOUT_FILENO);
		else if (one_op < 0 || another_op < 0)
			ft_putendl_fd("rrr", STDOUT_FILENO);
	}
}
