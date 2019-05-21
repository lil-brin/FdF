/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:44:43 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/05 19:16:31 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_line(char **line, char **rest)
{
	char	*a;
	char	*tmp;

	a = ft_strchr(*rest, '\n');
	tmp = *rest;
	if (a)
	{
		*a = '\0';
		*line = ft_strdup(*rest);
		*rest = ft_strdup(a + 1);
		free(tmp);
	}
	else if (ft_strlen(*rest) && (*line = ft_strdup(*rest)))
		ft_bzero(*rest, ft_strlen(*rest));
	else
		return (0);
	return (1);
}

int	read_get_next_line(const int fd, char **line, char **rest)
{
	char	*buff;
	char	*tmp;

	tmp = "";
	if (!*rest)
		*rest = ft_strnew(1);
	buff = ft_strnew(BUFF_SIZE);
	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	while (!ft_strchr(tmp, '\n') && read(fd, buff, BUFF_SIZE) > 0)
	{
		tmp = ft_strjoin(*rest, buff);
		free(*rest);
		*rest = tmp;
		ft_bzero(buff, BUFF_SIZE);
	}
	free(buff);
	return (write_line(line, rest));
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	t_list			*new_list;

	if ((fd < 0 || line == NULL))
		return (-1);
	tmp = list;
	if (!list)
	{
		list = ft_lstnew(NULL, 0);
		list->content_size = (size_t)fd;
		return (read_get_next_line(fd, line, (char**)&(list->content)));
	}
	else
		while (tmp)
		{
			if (tmp->content_size == (size_t)fd)
				return (read_get_next_line(fd, line, (char**)&(tmp->content)));
			tmp = tmp->next;
		}
	new_list = ft_lstnew(NULL, 0);
	new_list->content_size = (size_t)fd;
	ft_lstadd(&list, new_list);
	return (read_get_next_line(fd, line, (char**)&(new_list->content)));
}
