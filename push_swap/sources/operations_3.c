/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:43:52 by bemoreau          #+#    #+#             */
/*   Updated: 2021/05/05 18:48:14 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rev_rotate_b(int *stack, int len)
{
	int tmp;

	ft_putstr_fd("rrb\n", 1);
	tmp = stack[len - 1];
	while (len > 0)
	{
		ft_swap(&(stack[len]), &(stack[len - 1]));
		len--;
	}
	stack[0] = tmp;
}