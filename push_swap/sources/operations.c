/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:46 by bemoreau          #+#    #+#             */
/*   Updated: 2021/04/27 19:38:11 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(int *stack)
{
	int tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ss(t_stack *stack)
{
	swap(stack->a);
	swap(stack->b);
}

void	push_a(t_stack *stack)
{
	int tmp;

	if (stack->b_len == 0)
		return ;
	tmp = stack->a_len;
	while (--tmp >= 0)
		stack->a[tmp + 1] = stack->a[tmp];
	stack->a[0] = stack->b[0];
	stack->a_len++;
	tmp = -1;
	while (++tmp < stack->b_len)
		stack->b[tmp] = stack->b[tmp + 1];
	stack->b_len--;
}

void	push_b(t_stack *stack)
{
	int tmp;

	if (stack->a_len == 0)
		return ;
	tmp = stack->b_len;
	while (--tmp >= 0)
		stack->b[tmp + 1] = stack->b[tmp];
	stack->b_len++;
	stack->b[0] = stack->a[0];
	tmp = -1;
	while (++tmp < stack->a_len)
		stack->a[tmp] = stack->a[tmp + 1];
	stack->a_len--;
}