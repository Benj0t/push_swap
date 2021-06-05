/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:19:34 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 10:09:38 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_operation(char *operation, t_stack *stack)
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
		rotate(stack->a, stack->a_len);
	else if (!ft_strncmp(operation, "rr", 3))
		rr(stack);
	else if (!ft_strncmp(operation, "rra", 4))
		rev_rotate(stack->a, stack->a_len);
	else if (!ft_strncmp(operation, "rrb", 4))
		rev_rotate(stack->b, stack->b_len);
	else if (!ft_strncmp(operation, "rrr", 4))
		rrr(stack);
}

void	resolve(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->oper[i])
	{
		exec_operation(stack->oper[i], stack);
		i++;
	}
}
