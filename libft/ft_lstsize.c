/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:13:46 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/30 22:22:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*runner;
	int		count;

	runner = lst;
	count = 0;
	while (runner)
	{
		count++;
		runner = runner->next;
	}
	return (count);
}
