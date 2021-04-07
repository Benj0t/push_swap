/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:11:09 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/12 14:08:21 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = (unsigned char)c;
	return (s);
}
