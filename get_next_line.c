/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:14:51 by apaget            #+#    #+#             */
/*   Updated: 2015/12/16 19:15:28 by                  ###   ########.fr       */
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
	if (socket->buf[0] == '\0')
	{
		if((ret = read(socket->fd, socket->buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
		{
			*line = NULL;
			return (1);
		}
	}
	*tmp = ft_strchr(socket->buf, '\n');
	return (0);
}

int		make_line(t_sock *socket, char** line, char **tmp)
{
	if (*tmp)
	{
		*tmp = ft_strsub(socket->buf, 0, *tmp - socket->buf);
		*line = ft_strjoinfree(socket->line,*tmp);
		ft_strcpy(socket->buf, socket->buf + ft_strlen(*tmp) + 1);
		socket->line = 0x0;
		return (0);
	}
	else
	{
		socket->line = ft_strjoinfree(socket->line, socket->buf);
		socket->buf[0] = '\0';
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_sock	socket;
	char			*tmp;

	socket.fd = fd;
	if (!socket.line)
		if((socket.line = (char*)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
	while (1)

		if(xread(&socket, line, &tmp) != 0)
			return (xread(&socket, line, &tmp));
		if (!make_line(&socket, line, &tmp));
			return (0);
	}
	return (99);
}
int main(int argc, const char *argv[])
{
	char *line;
	line = NULL;
	int fd = open("fichiertest", O_RDONLY);
	int x = 0;

	while (!x)
	{
		x = get_next_line(fd, &line);
		printf("1 :Valeur de retour de gnl : %d \nLa ligne vaut : \"%s\" \n\n",x,line);

	}
	return 0;
}
