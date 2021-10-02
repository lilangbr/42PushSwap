/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:02:01 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/29 19:26:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_three(t_game *towers)
{
	int	bigger;
	int	ordered;

	bigger = get_bigger(&towers->a);
	ordered = 0;
	while (ordered == 0)
	{
		if (towers->a.top->normalized == bigger)
			move(towers, RA);
		else if (towers->a.top->next->normalized == bigger)
			move(towers, RRA);
		else
			move(towers, SA);
		ordered = is_ordered(&towers->a);
	}	
}
