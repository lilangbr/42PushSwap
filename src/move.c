/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:00:11 by ebresser          #+#    #+#             */
/*   Updated: 2021/09/22 21:33:59 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move(t_game *towers, int mov)
{
	char	which;
	int		tester;

	tester = mov % 2;
	if (tester == 1)
		which = 'a';
	else
		which = 'b';
	if (mov < 3)
		swap(towers, which);
	else if (mov < 5)
		push(towers, which);
	else if (mov < 7)
		rotate(towers, which, rotate_one);
	else if (mov < 10)
		rotate(towers, which, rev_rotate_one);
	else if (mov < 20)
		swap(towers, 'c');
	else if (mov < 30)
		rotate(towers, 'c', rotate_one);
	else
		rotate(towers, 'c', rev_rotate_one);
}
