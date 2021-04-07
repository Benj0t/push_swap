/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:57:49 by bemoreau          #+#    #+#             */
/*   Updated: 2021/03/11 18:43:10 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#define OPEN_MAX 4096
#define BUFFER_SIZE 1

typedef struct		s_struct
{
	int				len;
	int				ret;
	int				pos;
	char			*buffer;
	char			*tmp;
	char			*s[OPEN_MAX];
}					t_struct;

int					my_strlen(char *str);
int					get_next_line(int fd, char **line);
char				*my_calloc(int count, int size);
char				*my_strdup(char *src, int len);
char				*my_substr(char *s, unsigned int start,
					size_t len, int bool);
char				*my_strjoin(char *s1, char *s2, int len);

#endif
