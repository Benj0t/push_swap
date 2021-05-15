/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:12:29 by bemoreau          #+#    #+#             */
/*   Updated: 2021/05/14 17:49:18 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			check_ref(int *chunk, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (chunk[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int			get_biggest(int *stack, int *ref, int slen, int rlen)
{
	int i;
	int tmp;

	i = -1;
	tmp = -2147483648;
	if (!rlen)
	{
		while (++i < slen)
			if (stack[i] > tmp)
			{
				tmp = stack[i];
				i = -1;
			}
	}
	else
	{
		while (++i < slen) 
			if (stack[i] > tmp && check_ref(ref, rlen, stack[i]))
			{
				tmp = stack[i];
				i = -1;
			}
	}
	return (tmp);
}

void		init_chunk(t_stack *stack)
{
	int			len;
	static int	rest;
	static int	div;
	
	if (!rest)
	{
		rest = stack->a_len % 5;
		if (stack->a_len >= 500)
			rest = stack->a_len % 11;
	}
	if (!div)
	{
		div = stack->a_len / 5;
		if (stack->a_len >= 500)
			div = stack->a_len / 11;
	}
	len = -1;
	stack->c_len = div;
	if (div + rest == stack->a_len)
		stack->c_len += rest;
	stack->chunk = (int *)malloc(sizeof(int) * (stack->c_len + 1));
	if (!stack->chunk)
		exit_main(stack, 0);
	while (++len < stack->c_len)
		stack->chunk[len] = get_biggest(stack->a, stack->chunk,\
										stack->a_len, len);
	return;
}

int			hold_first(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->a_len)
	{
		if (!check_ref(stack->chunk, 20, stack->a[i]))
			return (i);
		i++;
	}
	return (-1);
}

int			hold_second(t_stack *stack)
{
	int i;

	i = stack->a_len - 1;
	while (i >= 0)
	{
		if (!check_ref(stack->chunk, stack->c_len, stack->a[i]))
			return (i);
		i--;
	}
	return (-1);
}
