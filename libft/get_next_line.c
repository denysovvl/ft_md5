/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <vdenysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:19:36 by vdenysov          #+#    #+#             */
/*   Updated: 2017/12/04 20:20:29 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_cur(t_gnl *current)
{
	free(current->string);
	free(current);
}

static t_gnl	*ft_get_fd(size_t fd, t_gnl **list)
{
	t_gnl			*current;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
		{
			if (!(current->string))
				current->string = ft_strnew(0);
			return (current);
		}
		current = current->next;
	}
	if (!(current = malloc(sizeof(*current))))
		return (NULL);
	current->fd = fd;
	current->string = ft_strnew(0);
	current->next = *list;
	*list = current;
	return (current);
}

static int		ft_getline(t_gnl *current, char **line)
{
	char			*tmp;
	char			*ptr;

	if (*(current->string))
	{
		if (!(ptr = ft_strchr(current->string, '\n')))
		{
			*line = current->string;
			current->string = NULL;
		}
		else
		{
			*line = ft_strnew(ptr - current->string);
			ft_memcpy(*line, current->string, ptr - current->string);
			tmp = current->string;
			current->string = ft_strdup(++ptr);
			ft_strdel(&tmp);
		}
		return (1);
	}
	return (0);
}

static int		ft_read(int fd, t_gnl *current)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = current->string;
		if (!(current->string = ft_strjoin(current->string, buff)))
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(current->string, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	if (ft_strlen(current->string) == 0)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*current;
	int				ret;
	int				read;

	if (!line || fd < 0)
		return (-1);
	current = ft_get_fd(fd, &list);
	if (!(ft_strchr(current->string, '\n')))
	{
		read = ft_read(fd, current);
		if (read == -1)
		{
			free_cur(current);
			return (-1);
		}
		if (read == 0)
		{
			free_cur(current);
			return (0);
		}
	}
	ret = ft_getline(current, line);
	return ((ret > 0) ? 1 : 0);
}
