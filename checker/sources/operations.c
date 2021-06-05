/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:46 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 10:08:06 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(int *stack)
{
	int	tmp;

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
	if (stack->b_len == 0)
		return ;
	stack->a[0] = stack->b[0];
}

void	push_b(t_stack *stack)
{
	if (stack->a_len == 0)
		return ;
	stack->b[0] = stack->a[0];
}
