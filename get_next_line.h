/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:30:27 by apaget            #+#    #+#             */
/*   Updated: 2016/01/08 20:12:18 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFF_SIZE 10

typedef struct		s_sock
{
	char			buf[BUFF_SIZE + 1];
	int				fd;
	char			*line;
}					t_sock;

int					get_next_line(int const fd, char **line);
char				*ft_strjoinfree(char *s1, char *s2);
int					xread(t_sock *socket, char **line, char **tmp);
int					make_line(t_sock *socket, char **line, char **tmp);

#endif
