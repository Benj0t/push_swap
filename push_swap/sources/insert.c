/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:22:32 by bemoreau          #+#    #+#             */
/*   Updated: 2021/04/27 23:29:05 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	insert_up(t_stack *stack, int pos)
{
	int count;

	while (pos++ < stack->a_len)
		rev_rotate(stack->a, stack->a_len);
	push_a(stack);
	count = get_min_pos(stack->a, stack->a_len);
	while (count-- >= 1)
		rotate(stack->a, stack->a_len);
}

void	insert_down(t_stack *stack, int pos)
{
	int count;

	while (pos-- > 1)
	{
		rotate(stack->a, stack->a_len);
	}
	push_a(stack);
	count = get_min_pos(stack->a, stack->a_len);
	while (count++ < stack->a_len)
		rev_rotate(stack->a, stack->a_len);
}
