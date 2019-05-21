/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:06:45 by vmuravio          #+#    #+#             */
/*   Updated: 2018/05/16 17:40:31 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_data *data)
{
	data->cords = NULL;
	data->flag = 0;
}

char	*create_image(void *img_ptr, int *size_line)
{
	char	*str_pixels;
	int		bits_per_pixel;
	int		endian;

	str_pixels = mlx_get_data_addr(img_ptr, \
	&bits_per_pixel, size_line, &endian);
	return (str_pixels);
}

int		main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (0);
	data.line_ptr = NULL;
	fd = open(av[1], O_RDONLY);
	data.y_max = count_new_lines(fd);
	fd = open(av[1], O_RDONLY);
	if (read(fd, data.line_ptr, 1) == 0)
		exit(0);
	close(fd);
	fd = open(av[1], O_RDONLY);
	init_data(&data);
	cords_to_struct(&data, fd, data.line_ptr, data.y_max);
	initialization(&data);
	first_zoom(&data);
	copy_struct(data.start_cords, data.cords, data);
	center_to_zero(&data, data.cords);
	to_center(&data);
	data.str_pixels = create_image(data.img_ptr, &data.size_line);
	mlx_hook(data.win_ptr, 2, 5, manipulations, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, exit_mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
