/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:38:27 by bemoreau          #+#    #+#             */
/*   Updated: 2021/03/22 16:03:44 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_main(t_stack *stack, int bool)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->oper)
		free_tab(stack->oper);
	if (bool)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

int		is_sort(t_stack *stack)	
{
	int		i;
	int		prev;

	i = 1;
	if (stack->b_len != 0)
		return (1);
	prev = stack->a[0];
	while (i < stack->a_len)
		if (prev > stack->a[i++])
			return (1);
	return (0);
}

int 	main(int argc, char **argv)
{
	t_stack	stack;

	stack.oper = NULL;
	stack.a = NULL;
	stack.b = NULL;
	if (argc <= 2 || check_num(argv) || init_stack(&stack, argc - 1, argv + 1))
		exit_main(&stack, 1);
	if (execution(stack))
		exit_main(&stack, 1);
	return (0);
}
