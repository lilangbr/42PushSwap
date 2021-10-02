/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:14:14 by user42            #+#    #+#             */
/*   Updated: 2021/09/29 19:26:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	which_algorithm(t_game *towers, int argc)
{
	if (argc == 2)
		order_two(towers);
	else
	{
		normalize(&towers->a, argc);
		if (argc == 3)
		{
			order_three(towers);
			free_stack(&towers->a);
		}		
		else if (argc == 4)
			order_three_plus(towers, 1);
		else if (argc == 5)
			order_three_plus(towers, 2);
		else
			order_more_than_five(towers, argc);
	}
}
