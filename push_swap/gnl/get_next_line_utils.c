/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 06:44:06 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/01 11:02:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*my_ft_strdup(char *src, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	i = -1;
	while (++i < len && src[i])
		str[i] = src[i];
	str[i] = '\0';
	free(src);
	src = NULL;
	return (str);
}

char	*ft_calloc(int count, int size)
{
	char	*ret;
	char	*c;
	int		i;
	int		len;

	c = NULL;
	if (!init_calloc(&size, &count, c, &len))
		return (NULL);
	i = 0;
	ret = (char *)malloc(len + 1);
	if (!(ret))
	{
		c = (char *)malloc(1);
		if (!(c))
			return (NULL);
		c[0] = 0;
		return ((void *)c);
	}
	while (i < len)
		ret[i++] = '\0';
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int bool)
{
	size_t	i;
	int		leng;
	char	*str;

	i = 0;
	leng = my_ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || (!(str)))
		return (NULL);
	if (!((unsigned int)leng < start))
		while (len-- > 0 && i < (size_t)leng)
			str[i++] = s[start++];
	str[i] = '\0';
	if (bool == 1)
	{
		free(s);
		s = NULL;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*pt;
	int		i;
	int		j;

	pt = malloc(sizeof(char) * (len + 1));
	if ((!s1 || !s2) || \
		(!(pt)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		pt[i++] = s1[j++];
	j = 0;
	while (s2[j])
		pt[i++] = s2[j++];
	pt[len] = '\0';
	free(s1);
	s1 = NULL;
	return (pt);
}
