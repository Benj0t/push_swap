/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:32:23 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/12 13:50:46 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (c == '\0')
		return ((char *)s + (ft_strlen(s)));
	i = -1;
	str = (char *)s;
	while (str[++i])
		if (str[i] == c)
			return (str + i);
	return (NULL);
}
