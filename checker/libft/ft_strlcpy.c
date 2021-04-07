/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:45:48 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/13 14:19:39 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!src || !dest)
		return (0);
	if (size > 1)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (size >= 1)
		dest[i] = '\0';
	return (ft_strlen(src));
}
