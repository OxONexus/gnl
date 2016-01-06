/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:14:51 by apaget            #+#    #+#             */
/*   Updated: 2016/01/06 19:50:35 by apaget           ###   ########.fr       */
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

int		xread(t_sock *socket, char **line, char **tmp)
{
	int ret;

	ret = 0;
	*tmp = ft_strchr(socket->buf, '\n');
	if (socket->buf[0] == -1)
	{
		if((ret = read(socket->fd, socket->buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
		{
			*line = NULL;
			socket->buf[0] = '\0';
			socket->line[0] = '\0';
			return (0);
		}
	}
	*tmp = ft_strchr(socket->buf, '\n');
	return (1);
}

int		make_line(t_sock *socket, char** line, char **tmp)
{
	if (*tmp)
	{
		*tmp = ft_strsub(socket->buf, 0, *tmp - socket->buf);
		*line = ft_strjoinfree(socket->line,*tmp);
		socket->line = NULL;
	 	ft_strcpy(socket->buf, socket->buf + ft_strlen(*tmp) + 1);
		free (*tmp);
		printf("line ; %s\n", *line);
		return (0);
	}
	else
	{
		socket->line = ft_strjoinfree(socket->line, socket->buf);
		socket->buf[0] = -1;
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_sock	socket;
	char			*tmp;
	int				tmp_int;

	tmp_int = 0;
	socket.fd = fd;
	*line = NULL;
	if (!socket.line)
		if((socket.line = (char*)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
	socket.line[0] = '\0';
	while (1)
	{
		tmp_int = xread(&socket, line, &tmp);
		if(tmp_int != 1)
			return (tmp_int);
		if (!make_line(&socket, line, &tmp))
			return (1);
	}
	return (99);
}
/*
int main(int argc, const char *argv[])
{
	char *line;
	line = NULL;
	int fd = open("fichiertest", O_RDONLY);
	int x = 1;

	while (x)
	{
		x = get_next_line(fd, &line);
		printf("1 :Valeur de retour de gnl : %d \nLa ligne vaut : \"%s\" \n\n",x,line);
		free(line);

	}
	return 0;
}*/
