/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:18:00 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/13 12:18:01 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}
