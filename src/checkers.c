/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:07:31 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/29 19:31:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ordered(t_stack *a)
{
	t_node	*element;

	element = a->top;
	while (element->next->next != NULL)
	{
		if (element->content < element->next->content)
			element = element->next;
		else
			return (0);
	}
	if (element->content < element->next->content)
		return (1);
	else
		return (0);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}
