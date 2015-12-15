/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:14:51 by apaget            #+#    #+#             */
/*   Updated: 2015/12/15 17:54:07 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	free(s1);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static t_sock socket;
	int ret;
	int count;
	char *tmp;
	int ok;

	ok = 0;
	ret = 0;
	count = 0;
	if (!socket.line)
		if((socket.line = (char*)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
	while (1)
	{
		tmp = ft_strrchr(socket.buf, '\n');
		if (tmp == NULL)
			if((ret = read(fd, socket.buf, BUFF_SIZE)) == -1)
				return (-1);
		if (tmp)
		{
			tmp = ft_strsub(socket.buf, 0, tmp + 1 - socket.buf);
			socket.line = ft_strjoinfree(socket.line, tmp + 1);
			ft_strcpy(socket.buf, tmp + 1);
			*line = socket.line;
			free(socket.line);
			return (0);
		}
		else
			socket.line = ft_strjoinfree(socket.line, socket.buf);
	}
	return (99);
}
