/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:19:12 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/01 11:24:42 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **line, t_struct *v, int fd)
{
	if (v->tmp)
		free(v->tmp);
	if (v->s[fd])
		free(v->s[fd]);
	if (v->buffer)
		free(v->buffer);
	if (*line)
		free(*line);
	v->tmp = NULL;
	v->s[fd] = NULL;
	v->buffer = NULL;
	line = NULL;
	return (-1);
}

static int	ft_charset(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*init_calloc(int *size, int *count, char *c, int *len)
{
	if (*size <= 0 || *count <= 0)
	{
		c = (char *)malloc(1);
		if (!(c))
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	*len = (*size) * (*count);
	return (c);
}

int	get_line(int fd, char **line, t_struct *v)
{
	v->ret = read(fd, v->buffer, BUFFER_SIZE);
	v->pos = ft_charset(v->s[fd]);
	while ((v->ret) > 0 && (v->pos) < 0)
	{
		v->buffer[v->ret] = '\0';
		v->len += v->ret;
		v->tmp = ft_strjoin(v->s[fd], v->buffer, v->len);
		if (!(v->tmp))
			return (ft_free(line, v, fd));
		v->s[fd] = my_ft_strdup(v->tmp, v->len);
		if (!(v->s[fd]))
			return (ft_free(line, v, fd));
		v->ret = read(fd, v->buffer, BUFFER_SIZE);
		v->pos = ft_charset(v->s[fd]);
	}
	return (1);
}
