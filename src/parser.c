/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:31:10 by vmuravio          #+#    #+#             */
/*   Updated: 2018/05/16 17:42:43 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validation(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!*str)
		exit(0);
	while (str[i])
	{
		if ((!ft_isdigit(*str[i])) && (!ft_isalpha(*str[i])) && *str[i] != '-')
			exit(0);
		i++;
	}
}

int		check_length(char **line)
{
	int	count;

	count = 0;
	while (line[count])
		count++;
	return (count);
}

int		count_new_lines(int fd)
{
	char	*line_ptr;
	int		count;
	int		i;

	count = 0;
	line_ptr = (char *)ft_memalloc(21);
	if (read(fd, line_ptr, 0) < 0)
		exit(0);
	while (read(fd, line_ptr, 20))
	{
		i = 0;
		while (line_ptr[i])
		{
			if (line_ptr[i] == '\n')
				count++;
			i++;
		}
		ft_bzero(line_ptr, ft_strlen(line_ptr) + 1);
	}
	free(line_ptr);
	close(fd);
	return (count);
}

void	check(t_data *data, char **cords_ptr)
{
	data->len = check_length(cords_ptr);
	if (data->prev_len != data->len && data->flag != 0)
		exit(0);
	data->prev_len = data->len;
	data->flag = 1;
}

void	cords_to_struct(t_data *data, int fd, char *line_ptr, int length)
{
	while (get_next_line(fd, &line_ptr))
	{
		data->x = -1;
		data->cords_ptr = ft_strsplit(line_ptr, ' ');
		validation(data->cords_ptr);
		free(line_ptr);
		check(data, data->cords_ptr);
		while (data->cords_ptr[++(data->x)])
		{
			if (!(data->cords))
				data->cords = (t_cords *)malloc(sizeof(t_cords) * \
				(data->len * length));
			(data->cords)[data->z].x = data->x;
			(data->cords)[data->z].y = data->y;
			(data->cords)[(data->z)++].z = \
			ft_atoi(data->cords_ptr[data->x]) * 3;
		}
		data->x_max = check_length(data->cords_ptr);
		data->x = 0;
		while (data->cords_ptr[data->x])
			free(data->cords_ptr[(data->x)++]);
		free(data->cords_ptr);
		(data->y)++;
	}
}
