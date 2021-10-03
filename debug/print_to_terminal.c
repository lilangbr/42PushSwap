/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:36:46 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/28 22:39:45 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void terminal(t_game *towers)
{
	t_node	*node;

	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
		
	node = towers->a.top;
	while( node != NULL)
	{
		ft_putnbr_fd(node->normalized, STDOUT_FILENO);		
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(node->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		node = node->next;
	}
	ft_putendl_fd("--------", 1);
	ft_putendl_fd("   a    ", 1);
	free_stack(&towers->a);
	node = towers->b.top;
	while( node != NULL)
	{
		ft_putnbr_fd(node->normalized, STDOUT_FILENO);		
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(node->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		node = node->next;
	}
	ft_putendl_fd("--------", 1);
	ft_putendl_fd("   b    ", 1);
	free_stack(&towers->b);			
}
