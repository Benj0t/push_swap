/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:43:52 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/04 15:09:05 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate_b(int *stack, int len)
{
	int	tmp;

	ft_putstr_fd("rrb\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		ft_swap(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	end_five_sort(t_stack *stack)
{
	int	ref;

	ref = get_max_pos(stack->a, stack->a_len);
	if (ref <= (stack->a_len / 2))
		while (ref-- >= 0)
			rotate_a(stack->a, stack->a_len);
	else
	{
		while (ref++ < stack->a_len - 1)
			rev_rotate_a(stack->a, stack->a_len);
	}
}

int	check_min_len(char *tab)
{
	int		j;
	char	*str;

	j = -1;
	str = "-2147483648";
	if (ft_strlen(tab) > ft_strlen(str) || tab[0] != str[++j])
		return (1);
	while (tab[++j])
	{
		if (tab[j] < str[j])
			return (0);
		if (tab[j] > str[j])
			return (1);
	}
	return (0);
}

int	check_len(char **tab)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = "2147483647";
	while (tab[++i])
	{
		if (tab[i][0] == '-' && !check_min_len(tab[i]))
			return (0);
		if (ft_strlen(tab[i]) > ft_strlen(str))
			return (1);
		while (tab[i][++j])
		{
			if (tab[i][j] < str[j])
				return (0);
			if (tab[i][j] > str[j])
				return (1);
		}
		j = 0;
	}
	return (0);
}
