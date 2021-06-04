/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:55:05 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/04 14:27:14 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	find_it(int slen, int *stack, int *tmp, int rlen)
{
	int	i;

	i = 0;
	if (!rlen)
	{
		while (i < slen)
		{
			if (stack[i] > *tmp)
			{
				*tmp = stack[i];
				i = -1;
			}
			i++;
		}
	}
}

void	init_op(int *rest, int *div, t_stack *stack)
{
	if (!*rest)
	{
		*rest = stack->a_len % 5;
		if (stack->a_len >= 500)
			*rest = stack->a_len % 11;
	}
	if (!*div)
	{
		*div = stack->a_len / 5;
		if (stack->a_len >= 500)
			*div = stack->a_len / 11;
	}
}
