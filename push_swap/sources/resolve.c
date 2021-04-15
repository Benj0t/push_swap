/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:19:34 by bemoreau          #+#    #+#             */
/*   Updated: 2021/03/31 04:42:34 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		exec_operation(char *operation, t_stack *stack)
{
	if (!ft_strncmp(operation, "sa", 3))
		swap(stack->a);
	else if (!ft_strncmp(operation, "sb", 3))
		swap(stack->b);
	else if (!ft_strncmp(operation, "ss", 3))
		ss(stack);
	else if (!ft_strncmp(operation, "pa", 3))
		push_a(stack);
	else if (!ft_strncmp(operation, "pb", 3))
		push_b(stack);
	else if (!ft_strncmp(operation, "ra", 3))
		rotate(stack->a, stack->a_len);
	else if (!ft_strncmp(operation, "rb", 3))
		rotate(stack->b, stack->b_len);
	else if (!ft_strncmp(operation, "rr", 3))
		rr(stack);
	else if (!ft_strncmp(operation, "rra", 4))
		rev_rotate(stack->a, stack->a_len);
	else if (!ft_strncmp(operation, "rrb", 4))
		rev_rotate(stack->b, stack->b_len);
	else if (!ft_strncmp(operation, "rrr", 4))
		rrr(stack);
}

void	three_sort(t_stack *stack)
{
	if (stack->a_len == 2)
		if (stack->a[0] < stack->a[1])
			swap(stack->a);
	if (stack->a_len == 3)
	{
		if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] &&\
			stack->a[2] > stack->a[0])
			swap(stack->a);
		else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
		{
			swap(stack->a);
			rev_rotate(stack->a, stack->a_len);
		}
		else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] &&\
			stack->a[2] < stack->a[0])
			rotate(stack->a, stack->a_len);
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] &&\
			stack->a[2] > stack->a[0])
		{
			swap(stack->a);
			rotate(stack->a, stack->a_len);
		}
		else
			rev_rotate(stack->a, stack->a_len);
	}
}

void	five_sort(t_stack *stack)
{
	int pos;

	while (stack->a_len != 3)
		push_b(stack);
	three_sort(stack);
	while (stack->b_len != 0)
	{
		pos = get_num_position(stack->a, first_sup(stack->a, stack->a_len, stack->b[0]));
		if (pos < (stack->a_len / 2))
			insert_up(stack, pos);
		else
		{
			insert_down(stack, pos);
		}
	}
}

void	hundred_sort(t_stack *stack)
{
	//PAUUUUUUUUUUUUUSE
}

int		execution(t_stack *stack)
{
	if (stack->a_len <= 3)
		three_sort(stack);
	else if (stack->a_len <= 5)
		five_sort(stack);
	else if (stack->a_len <= 100)
		hundred_sort(stack);
}
