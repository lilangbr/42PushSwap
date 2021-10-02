/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:45:07 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 22:59:44 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*last_node(t_stack *stack)
{
	t_node	*aux;

	if (stack->top == NULL)
		return (NULL);
	else
	{
		aux = stack->top;
		while (aux->next != NULL)
			aux = aux->next;
		return (aux);
	}
}

t_node	*penult_node(t_stack *stack)
{
	t_node	*aux;

	if (stack->top == NULL)
		return (NULL);
	else
	{
		aux = stack->top;
		while (aux->next->next != NULL)
			aux = aux->next;
		return (aux);
	}
}

int	get_smaller(t_stack *a)
{
	t_node	*aux;
	int		smaller;

	if (a->top == NULL)
		return (0);
	smaller = INT_MAX;
	aux = a->top;
	if (a->top->content < smaller && a->top->normalized == -1)
		smaller = a->top->content;
	while (aux->next != NULL)
	{
		aux = aux->next;
		if (aux->content < smaller && aux->normalized == -1)
			smaller = aux->content;
	}
	return (smaller);
}

int	get_bigger(t_stack *stack)
{
	int		bigger;
	t_node	*aux;

	if (stack->top == NULL)
		return (0);
	bigger = 0;
	aux = stack->top;
	if (aux->normalized > bigger)
		bigger = aux->normalized;
	while (aux->next != NULL)
	{
		aux = aux->next;
		if (aux->normalized > bigger)
			bigger = aux->normalized;
	}
	return (bigger);
}

int	get_binary_digits(int number)
{
	int	i;
	int	digits;

	digits = 0;
	i = number;
	while (i > 0)
	{
		digits = digits + 1;
		i = i >> 1;
	}
	return (digits);
}
