/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:44:29 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/06 11:33:36 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialization(t_data *data)
{
	data->ofset_x = 0;
	data->ofset_y = 0;
	data->center_x = WIDTH / 2;
	data->center_y = HEIGHT / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->pixels = data->x_max * data->y_max;
	if (data->x_max > 2)
		data->zoom = WIDTH / data->x_max / 2;
	else
		data->zoom = 20;
	data->x_degree = 0;
	data->y_degree = 0;
	data->z_degree = 0;
	data->red = 255;
	data->green = 255;
	data->blue = 255;
	data->prev_len = 255;
	data->start_cords = (t_cords *)malloc(sizeof(t_cords) * (data->pixels + 1));
	data->y = 0;
	data->z = 0;
}
