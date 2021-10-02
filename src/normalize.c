/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:06:54 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 23:01:20 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	norm_node(t_stack *a, int goal, int norm)
{
	t_node	*aux;

	if (a->top == NULL)
		return (0);
	aux = a->top;
	if (aux->content == goal)
	{
		aux->normalized = norm;
		return (0);
	}
	while (aux->next != NULL)
	{
		aux = aux->next;
		if (aux->content == goal)
		{
			aux->normalized = norm;
			return (0);
		}
	}
	return (1);
}

int	normalize(t_stack *a, int argc)
{
	int	count;
	int	smaller;

	if (a->top == NULL)
		return (0);
	count = 0;
	while (count < argc)
	{
		smaller = get_smaller(a);
		norm_node(a, smaller, count);
		count++;
	}
	return (0);
}
