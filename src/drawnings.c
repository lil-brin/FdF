/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawnings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:30:35 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/05 16:35:36 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			draw_line2(t_data *data)
{
	put_pix_on_image(data->cords_to_draw.x0, \
						data->cords_to_draw.y0, *data);
	if (data->cords_to_draw.x0 == data->cords_to_draw.x1 \
			&& data->cords_to_draw.y0 == data->cords_to_draw.y1)
		return (0);
	data->brezenhem.e2 = data->brezenhem.err;
	if (data->brezenhem.e2 > -(data->brezenhem.dx))
	{
		data->brezenhem.err -= data->brezenhem.dy;
		data->cords_to_draw.x0 += data->brezenhem.sx;
	}
	if (data->brezenhem.e2 < data->brezenhem.dy)
	{
		data->brezenhem.err += data->brezenhem.dx;
		data->cords_to_draw.y0 += data->brezenhem.sy;
	}
	return (1);
}

void		draw_line(t_cords cords0, t_cords cords1, t_data *data)
{
	data->cords_to_draw.x0 = (int)cords0.x;
	data->cords_to_draw.y0 = (int)cords0.y;
	data->cords_to_draw.x1 = (int)cords1.x;
	data->cords_to_draw.y1 = (int)cords1.y;
	data->brezenhem.dx = abs(data->cords_to_draw.x1 - data->cords_to_draw.x0);
	data->brezenhem.sx = data->cords_to_draw.x0 \
			< data->cords_to_draw.x1 ? 1 : -1;
	data->brezenhem.dy = abs(data->cords_to_draw.y1 - \
									data->cords_to_draw.y0);
	data->brezenhem.sy = data->cords_to_draw.y0 \
			< data->cords_to_draw.y1 ? 1 : -1;
	data->brezenhem.err = (data->brezenhem.dx > data->brezenhem.dy ? \
			data->brezenhem.dx : -(data->brezenhem.dy)) / 2;
	while (1)
		if (!draw_line2(data))
			return ;
}

void		draw_all_lines(t_data *data)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	while (i < data->pixels)
	{
		if (x == (data->x_max))
			x = 0;
		if (x < (data->x_max - 1))
			draw_line(data->cords[i], data->cords[i + 1], \
					data);
		if (i < (data->pixels - data->x_max))
			draw_line(data->cords[i], data->cords[i + data->x_max], \
					data);
		i++;
		x++;
	}
}

void		put_pix_on_image(int x, int y, t_data data)
{
	int	i;

	i = (x * 4) + (y * data.size_line);
	if (x >= WIDTH || y >= HEIGHT)
		return ;
	if (x >= 0 && y >= 0)
	{
		data.str_pixels[i++] = (char)data.blue;
		data.str_pixels[i++] = (char)data.green;
		data.str_pixels[i] = (char)data.red;
	}
}

void		draw_image(t_data *data)
{
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 5, 0xFFFFFF, "Rotate x - RIGHT");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 30, 0xFFFFFF, "Rotate y - UP");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 55, 0xFFFFFF, "Rotate z - LEFT");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 80, 0xFFFFFF, "Paint to red - R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 110, 0xFFFFFF, "Paint to green - G");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 140, 0xFFFFFF, "Paint to blue - B");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 170, 0xFFFFFF, "Increase z - +");
	mlx_string_put(data->mlx_ptr, data->win_ptr, \
				10, 200, 0xFFFFFF, "Decrease z - -");
	ft_bzero(data->str_pixels, WIDTH * HEIGHT * 4);
}
