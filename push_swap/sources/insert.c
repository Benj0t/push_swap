/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:22:32 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/04 15:06:21 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	insert_up(t_stack *stack, int pos)
{
	int	count;

	while (pos++ <= stack->a_len)
		rev_rotate_a(stack->a, stack->a_len);
	push_a(stack);
	count = get_min_pos(stack->a, stack->a_len);
	while (count-- >= 1)
		rotate_a(stack->a, stack->a_len);
}

void	insert_down(t_stack *stack, int pos)
{
	int	count;

	while (pos-- > 1)
		rotate_a(stack->a, stack->a_len);
	push_a(stack);
	count = get_min_pos(stack->a, stack->a_len);
	while (count++ < stack->a_len)
		rev_rotate_a(stack->a, stack->a_len);
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

	while (pos-- > 0)
		rev_rotate_a(stack->a, stack->a_len);
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
													stack->a[0]));
	insert_switch(stack, position);
}

void	push_down(t_stack *stack, int pos)
{
	int	position;

	while (pos-- > 0)
		rotate_a(stack->a, stack->a_len);
	position = get_num_position(stack->b, first_inf(stack->b, stack->b_len, \
								stack->a[0]));
	insert_switch(stack, position);
}
