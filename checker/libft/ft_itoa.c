/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:25:12 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/06 17:37:55 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mv_index(int n, int i)
{
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_imin(void)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * (12))))
		return (NULL);
	str[11] = '\0';
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*str;

	neg = 0;
	if (n == -2147483648)
		return (ft_imin());
	neg = (n < 0) ? 1 : 0;
	i = (n < 0) ? 2 : 1;
	n = (n < 0) ? -n : n;
	i = ft_mv_index(n, i);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[i] = '\0';
	while (i--)
	{
		if (str[i] == '-')
			break ;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
