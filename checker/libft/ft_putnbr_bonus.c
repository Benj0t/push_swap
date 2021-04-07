/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:43 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/13 12:18:10 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = (n < 0) ? -n : n;
	(n < 0) ? ft_putchar('-') : NULL;
	(nb >= 10) ? ft_putnbr(nb / 10) : NULL;
	ft_putchar(nb % 10 + '0');
}
