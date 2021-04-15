/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:37:55 by bemoreau          #+#    #+#             */
/*   Updated: 2021/03/22 15:39:00 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate(int *stack, int len)
{
	int i;

	i = 0;
	while (i + 1 < len)
	{
		ft_swap(&(stack[i]), &(stack[i + 1]));
		i++;
	}
}

void		rr(t_stack *stack)
{
	rotate(stack->a, stack->a_len);
	rotate(stack->b, stack->b_len);
}

void		rev_rotate(int *stack, int len)
{
	while (len > 0)
	{
		ft_swap(&(stack[len]), &(stack[len - 1]));
		len--;
	}
}

void		rrr(t_stack *stack)
{
	rev_rotate(stack->a, stack->a_len);
	rev_rotate(stack->b, stack->b_len);
}
