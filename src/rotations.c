/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:43:54 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/04 15:37:22 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_data *data, t_cords *cords, int offset)
{
	size_t	i;
	double	radian;
	double	y;

	i = 0;
	data->x_degree -= offset;
	radian = data->x_degree * M_PI / 180;
	while (i < data->pixels)
	{
		y = cords[i].y;
		cords[i].y = (cords[i].y * cos(radian)) + (cords[i].z * sin(radian));
		cords[i].z = -(y * sin(radian)) + (cords[i].z * cos(radian));
		i++;
	}
}

void	rotate_y(t_data *data, t_cords *cords, int offset)
{
	size_t i;
	double x;
	double radian;

	i = 0;
	data->y_degree += offset;
	radian = data->y_degree * M_PI / 180;
	while (i < data->pixels)
	{
		x = cords[i].x;
		cords[i].x = (cords[i].x * cos(radian)) + (cords[i].z * sin(radian));
		cords[i].z = -(x * sin(radian)) + (cords[i].z * cos(radian));
		i++;
	}
}

void	rotate_z(t_data *data, t_cords *cords, int offset)
{
	size_t i;
	double x;
	double radian;

	i = 0;
	data->z_degree += offset;
	radian = data->z_degree * M_PI / 180;
	while (i < data->pixels)
	{
		x = cords[i].x;
		cords[i].x = (cords[i].x * cos(radian)) - (cords[i].y * sin(radian));
		cords[i].y = (x * sin(radian)) + (cords[i].y * cos(radian));
		i++;
	}
}

void	rotate(t_data *data, int x, int y, int z)
{
	rotate_x(data, data->cords, x);
	rotate_y(data, data->cords, y);
	rotate_z(data, data->cords, z);
}
