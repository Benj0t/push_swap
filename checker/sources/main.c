/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:38:27 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 10:07:14 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_main(char *line, t_stack *stack, int bool)
{
	if (line)
		free(line);
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

int	is_sort(t_stack *stack)	
{
	int		i;
	int		prev;

	i = 1;
	if (stack->b_len != 0)
		return (1);
	prev = stack->a[0];
	while (i < stack->a_len)
	{
		if (prev > stack->a[i++])
			return (1);
	}
	return (0);
}

void	print_result(int status, t_stack *stack, char *line)
{
	if (status)
	{
		ft_putstr_fd("KO\n", 1);
		exit_main(line, stack, 0);
	}
	if (!status)
	{
		ft_putstr_fd("OK\n", 1);
		exit_main(line, stack, 0);
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	stack;

	stack.oper = NULL;
	stack.a = NULL;
	line = NULL;
	stack.b = NULL;
	if (argc <= 2 || check_num(argv) || init_stack(&stack, argc - 1, argv + 1))
		exit_main(line, &stack, 1);
	while ((get_next_line(0, &line)) > 0)
	{
		stack.oper = realloc_tab(stack.oper, line);
		if ((stack.oper) == NULL)
			return (1);
		free(line);
	}
	if (valid_operations(stack.oper, 0))
		exit_main(line, &stack, 1);
	resolve(&stack);
	print_result(is_sort(&stack), &stack, line);
	return (0);
}
