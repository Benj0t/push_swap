/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:57:49 by bemoreau          #+#    #+#             */
/*   Updated: 2021/06/04 10:44:31 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_struct
{
	int				len;
	int				ret;
	int				pos;
	char			*buffer;
	char			*tmp;
	char			*s[4096];
}				t_struct;

char				*init_calloc(int *size, int *count, char *c, int *len);
int					get_line(int fd, char **line, t_struct *v);
int					ft_strlen(char *str);
int					get_next_line(int fd, char **line);
char				*ft_calloc(int count, int size);
char				*ft_strdup(char *src, int len);
char				*ft_substr(char *s, unsigned int start, \
					size_t len, int bool);
char				*ft_strjoin(char *s1, char *s2, int len);

#endif
