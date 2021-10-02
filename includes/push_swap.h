/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:59:30 by ebresser          #+#    #+#             */
/*   Updated: 2021/10/02 15:34:19 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

# define SA 1
# define SB 2
# define SS 10

# define PA 3
# define PB 4

# define RA 5
# define RB 6
# define RR 20

# define RRA 7
# define RRB 8
# define RRR 30

typedef struct s_node
{
	int				content;
	int				normalized;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
}				t_stack;

typedef struct s_game
{
	t_stack	a;
	t_stack	b;
}				t_game;

void	validate_args(int argc, char **argv);

void	init_stacks(t_game *towers);
void	fill_a_stack(int argc, char **argv, t_game *towers);
int		normalize(t_stack *a, int argc);

int		is_ordered(t_stack *a);
int		is_empty(t_stack *stack);
void	free_stack(t_stack *s);

t_node	*new_node(int content, int norm);
t_node	*last_node(t_stack *stack);
t_node	*penult_node(t_stack *stack);

void	push_one(t_stack *stack, t_node *node);
void	pop_one(t_stack *stack);
int		rotate_one(t_stack *stack);
int		rev_rotate_one(t_stack *stack);
int		swap_one(t_stack *stack);
int		get_bigger(t_stack *stack);
int		get_smaller(t_stack *a);
int		get_binary_digits(int number);

void	swap(t_game *towers, char which_stack);
void	push(t_game *towers, char which_stack);
void	rotate(t_game *towers, char which_stack, int (*f)(t_stack *stack));
void	move(t_game *towers, int mov);

void	which_algorithm(t_game *towers, int argc);
void	order_two(t_game *towers);
void	order_three(t_game *towers);
void	order_three_plus(t_game *towers, int plus);
void	order_more_than_five(t_game *towers, int t_size_a);

void	error(void);
void	malloc_error(t_game *towers);

#endif
