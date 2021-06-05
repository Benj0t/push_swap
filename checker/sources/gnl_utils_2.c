/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:42:47 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/05 10:02:38 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, char **line, t_struct *v)
{
	v->ret = read(fd, v->buffer, BUFFER_SIZE);
	v->pos = my_charset(v->s[fd]);
	while ((v->ret) > 0 && (v->pos) < 0)
	{
		v->buffer[v->ret] = '\0';
		v->len += v->ret;
		v->tmp = my_strjoin(v->s[fd], v->buffer, v->len);
		if (!(v->tmp))
			return (my_free(line, v, fd));
		v->s[fd] = my_strdup(v->tmp, v->len);
		if (!(v->s[fd]))
			return (my_free(line, v, fd));
		v->ret = read(fd, v->buffer, BUFFER_SIZE);
		v->pos = my_charset(v->s[fd]);
	}
	return (1);
}
