/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:22:32 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 12:05:18 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	insert_up(t_stack *stack, int pos)
{
	while (pos++ <= stack->a_len)
		rev_rotate_a(stack->a, stack->a_len);
	push_a(stack);
}

void	insert_down(t_stack *stack, int pos)
{
	while (pos-- > 1)
		rotate_a(stack->a, stack->a_len);
	push_a(stack);
}

void	insert_switch(t_stack *stack, int pos)
{
	if ((stack->b_len / 2) < pos)
	{
		while (pos++ < stack->b_len)
			rev_rotate_b(stack->b, stack->b_len);
	}
	else
	{
		while (pos-- >= 1)
			rotate_b(stack->b, stack->b_len);
	}
	push_b(stack);
}

void	push_up(t_stack *stack, int pos)
{
	int	position;

	//printf("stack position: %d | first stack nb atm: %d\n", stack->a[pos], stack->a[0]);
	while (pos-- > 0)
		rotate_a(stack->a, stack->a_len);
	// printf("first stack position now: %d", stack->a[0]); 
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
													stack->a[0]));
	if (position == -1)
		position = get_max_pos(stack->b, stack->b_len);
	insert_switch(stack, position);
}

void	push_down(t_stack *stack, int pos)
{
	int	position;

	while (pos-- >= 0)
		rev_rotate_a(stack->a, stack->a_len);
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
								stack->a[0]));
	if (position == -1)
		position = get_max_pos(stack->b, stack->b_len);
	insert_switch(stack, position);
}
