/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:45:48 by ebresser          #+#    #+#             */
/*   Updated: 2021/10/02 15:28:23 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int content, int norm)
{
	t_node	*node;

	node = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->content = content;
		node->normalized = norm;
		node->next = NULL;
	}
	return (node);
}

void	free_stack(t_stack *s)
{
	t_node	*aux;
	t_node	*node;

	node = s->top;
	while (node != NULL)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
}

void	malloc_error(t_game *towers)
{
	free_stack(&towers->a);
	free_stack(&towers->b);
	error();
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
