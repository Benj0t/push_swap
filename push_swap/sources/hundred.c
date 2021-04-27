/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:12:29 by bemoreau          #+#    #+#             */
/*   Updated: 2021/04/27 17:16:59 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_ref(int *chunk, int len, int num)
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

int		get_lowest(int *stack, int *ref, int slen, int rlen)
{
	int i;
	int tmp;

	i = -1;
	tmp = stack[0];
	if (!rlen)
	{
		while (++i < slen)
			if (stack[i] < tmp)
			{
				tmp = stack[i];
				i = -1;
			}
	}
	else
	{
		while (++i < slen)
			if (stack[i] < tmp && check_ref(ref, rlen, stack[i]))
			{
				tmp = stack[i];
				i = -1;
			}
	}
	return (tmp);
}

void		init_chunk(t_stack *stack)
{
	int len;
	
	len = 0;
	while (len < 20)
	{
		stack->chunk[len] = get_lowest(stack->a, stack->chunk,\
										stack->a_len, len);
		len++;
	}
	return;
}

int		 hold_first(int *stack, int start, int end)
{
	(void)stack;
	(void)start;
	(void)end;
	return (1);
}