/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:55:40 by ebresser          #+#    #+#             */
/*   Updated: 2021/10/02 15:34:12 by ebresser         ###   ########.fr       */
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
	fill_a_stack(argc, argv, &towers);
	if (is_ordered(&towers.a))
	{
		free_stack(&towers.a);
		return (0);
	}		
	else
		which_algorithm(&towers, argc);
	return (0);
}
