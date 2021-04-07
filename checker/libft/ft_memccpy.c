/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:11:47 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/11 17:58:38 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		*dest;

	i = 0;
	if (!destination && !source)
		return (NULL);
	src = source;
	dest = destination;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
