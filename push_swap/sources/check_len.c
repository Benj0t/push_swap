/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:00:00 by bemoreau          #+#    #+#             */
/*   Updated: 2021/12/14 15:02:11 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_sign(char *tab)
{
	if (tab[0] == '-')
		return (1);
	if (tab[0] == '+')
		return (2);
	return (0);
}

int	parse_num(char *tab, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = "2147483647";
	if (sign == 1)
		str = "-2147483648";
	if (sign == 2)
		str = "+2147483647";
	while (tab[i])
	{
		if (tab[i] < str[i])
			return (0);
		if (tab[i] > str[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char **argv)
{
	int	i;
	int	sign;

	i = 1;
	while (argv[i])
	{
		sign = get_sign(argv[i]);
		if (ft_strlen(argv[i]) > 11 || \
			(ft_strlen(argv[i]) == 11 && sign == 0))
			return (1);
		if (ft_strlen(argv[i]) >= 10 && parse_num(argv[i], sign))
			return (1);
		i++;
	}
	return (0);
}
