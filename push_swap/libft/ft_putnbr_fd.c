/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:43 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/12 13:51:47 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (fd < 0)
		return ;
	nb = (n < 0) ? -n : n;
	(n < 0) ? ft_putchar_fd('-', fd) : NULL;
	(nb >= 10) ? ft_putnbr_fd(nb / 10, fd) : NULL;
	ft_putchar_fd(nb % 10 + '0', fd);
}
