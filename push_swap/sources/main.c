/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:38:27 by bemoreau          #+#    #+#             */
/*   Updated: 2021/05/05 22:21:25 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_main(t_stack *stack, int bool)
{
	if (stack->chunk)
		free(stack->chunk);
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

void	print_stack(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(stack[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int 	main(int argc, char **argv)
{
	t_stack	stack;

	stack.oper = NULL;
	stack.a = NULL;
	stack.b = NULL;
	if (argc <= 2 || check_num(argv) || init_stack(&stack, argc - 1, argv + 1))
		exit_main(&stack, 1);
	if (execution(&stack))
		exit_main(&stack, 1);
	
	//print_stack(stack.b, stack.b_len);
	exit_main(&stack, 0);
	return (0);
}
