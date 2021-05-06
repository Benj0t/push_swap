/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:24:12 by bemoreau          #+#    #+#             */
/*   Updated: 2021/05/05 23:48:58 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_max_pos(int *stack, int len)
{
	int max;
	int i;

	i = 1;
	if (len == 0)
		return (0);
	max = -2147483648;
	while (i < len)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	i = -1;
	while (++i < len)
		if (stack[i] == max)
			return (i);
	return (i);
}

int	get_min_pos(int *stack, int len)
{
	int less;
	int i;

	i = 1;
	if (len == 0)
		return (0);
	less = 2147483647;
	while (i < len)
	{
		if (stack[i] < less)
			less = stack[i];
		i++;
	}
	i = -1;
	while (++i < len)
		if (stack[i]  == less)
			return (i);
	return (i);
}

int	get_num_position(int *stack, int num)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i++] == num)
			return (i);
	}
	return (-1);
}

int	first_sup(int *stack, int len, int num)
{
	int i;
	int ref;

	i = 0;
	ref = stack[get_max_pos(stack, len)];
	while (i < len)
	{
		if (stack[i] > num && stack[i] < ref)
			ref = stack[i];
		i++;
	}
	if (num > ref)
		return (stack[get_min_pos(stack, len)]);
	return (ref);
}