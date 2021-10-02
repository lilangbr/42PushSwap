/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:55:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/29 19:31:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	towers;	

	if (argc == 1 || argc == 2)
		return (0);
	argc--;
	argv++;
	validate_args(argc, argv);
	init_stacks(&towers);
	fill_a_stack(argc, argv, &towers.a);
	if (is_ordered(&towers.a))
	{
		free_stack(&towers.a);
		return (0);
	}		
	else
		which_algorithm(&towers, argc);
	return (0);
}
