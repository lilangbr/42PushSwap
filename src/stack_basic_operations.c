/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:44:36 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 23:07:49 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_one(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
}

void	pop_one(t_stack *stack)
{
	t_node	*aux;

	if (stack->top != NULL)
	{
		aux = stack->top;
		stack->top = stack->top->next;
		free(aux);
	}
}

int	rotate_one(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (stack->top != NULL)
	{
		if (stack->top->next != NULL)
		{
			last = last_node(stack);
			last->next = stack->top;
			first = stack->top;
			stack->top = stack->top->next;
			first->next = NULL;
			return (1);
		}
	}
	return (0);
}

int	rev_rotate_one(t_stack *stack)
{
	t_node	*penult;

	if (stack->top != NULL)
	{
		if (stack->top->next != NULL)
		{
			penult = penult_node(stack);
			penult->next->next = stack->top;
			stack->top = penult->next;
			penult->next = NULL;
			return (-1);
		}
	}
	return (0);
}

int	swap_one(t_stack *stack)
{
	t_node	*aux;

	if (stack->top == NULL)
		return (0);
	if (stack->top->next != NULL)
	{
		aux = stack->top;
		stack->top = aux->next;
		aux->next = stack->top->next;
		stack->top->next = aux;
		return (1);
	}
	else
		return (0);
}
