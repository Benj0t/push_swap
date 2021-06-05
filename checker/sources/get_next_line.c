/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:51:24 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 10:02:22 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	my_free(char **line, t_struct *v, int fd)
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

int	my_charset(char *str)
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

static int	my_ret(t_struct *v, char **line, int fd, int bool)
{
	v->pos = my_charset(v->s[fd]);
	v->len = my_strlen(v->s[fd]);
	if (bool == 0)
	{
		*line = my_strdup(v->s[fd], v->len);
		v->s[fd] = NULL;
		return (0);
	}
	if (bool == 1 || bool == 2)
	{
		v->len = v->len - v->pos;
		*line = my_substr(v->s[fd], 0, v->pos, 0);
		if (!*line)
			return (my_free(line, v, fd));
		v->tmp = my_substr(v->s[fd], v->pos + 1, v->len, 1);
		if (!v->tmp)
			return (my_free(line, v, fd));
		v->s[fd] = my_strdup(v->tmp, v->len);
		if ((bool == 2 || bool == 1) && !(v->s[fd]))
			return (my_free(line, v, fd));
		return (1);
	}
	return (-1);
}

static int	my_gnl(int fd, char **line, t_struct *v)
{
	if (get_line(fd, line, v) == -1)
		return (-1);
	v->len += v->ret;
	v->buffer[v->ret] = '\0';
	v->tmp = my_strjoin(v->s[fd], v->buffer, v->len);
	if (!(v->tmp))
		return (my_free(line, v, fd));
	v->s[fd] = my_strdup(v->tmp, v->len);
	if (!(v->s[fd]))
		return (my_free(line, v, fd));
	v->pos = my_charset(v->s[fd]);
	free(v->buffer);
	v->buffer = NULL;
	if (v->pos >= 0)
		return (my_ret(v, line, fd, 2));
	else if (v->ret == 0)
		return (my_ret(v, line, fd, 0));
	return (my_free(line, v, fd));
}

int	get_next_line(int fd, char **line)
{
	static t_struct	v;

	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!v.s[fd])
	{
		v.s[fd] = my_calloc(0, 0);
		if (!(v.s[fd]))
			return (my_free(line, &v, fd));
	}
	v.buffer = my_calloc(1, BUFFER_SIZE + 1);
	if (!(v.buffer))
		return (my_free(line, &v, fd));
	v.len = my_strlen(v.s[fd]);
	v.pos = my_charset(v.s[fd]);
	if (v.pos >= 0)
	{
		free(v.buffer);
		v.buffer = NULL;
		return (my_ret(&v, line, fd, 1));
	}
	return (my_gnl(fd, line, &v));
}
