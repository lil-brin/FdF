/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:50:51 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/04 15:30:20 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_right(t_data *data, int pixels)
{
	size_t i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].x += pixels;
		i++;
	}
	data->ofset_x += pixels;
	data->center_x += pixels;
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_bzero(data->str_pixels, WIDTH * HEIGHT * 4);
}

void	move_left(t_data *data, int pixels)
{
	size_t i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].x -= pixels;
		i++;
	}
	data->ofset_x -= pixels;
	data->center_x -= pixels;
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_bzero(data->str_pixels, WIDTH * HEIGHT * 4);
}

void	move_up(t_data *data, int pixels)
{
	size_t i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].y -= pixels;
		i++;
	}
	data->ofset_y -= pixels;
	data->center_y -= pixels;
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_bzero(data->str_pixels, WIDTH * HEIGHT * 4);
}

void	move_down(t_data *data, int pixels)
{
	size_t i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].y += pixels;
		i++;
	}
	data->ofset_y += pixels;
	data->center_y += pixels;
	draw_all_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_bzero(data->str_pixels, WIDTH * HEIGHT * 4);
}

void	to_center(t_data *data)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].x += WIDTH / 2;
		data->cords[i].y += HEIGHT / 2;
		i++;
	}
	data->ofset_x = WIDTH / 2;
	data->ofset_y = HEIGHT / 2;
}
