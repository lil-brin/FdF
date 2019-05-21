/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:17:31 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/21 15:01:50 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_to_zero(t_data *data, t_cords *cords)
{
	double	shift_x;
	double	shift_y;
	size_t	i;

	i = 0;
	shift_x = ((data->x_max - 1) * \
			(data->cords[1].x - data->cords[0].x)) / 2;
	shift_y = ((data->y_max - 1) * \
			(data->cords[data->x_max].y - data->cords[0].y)) / 2;
	while (i < data->pixels)
	{
		cords[i].x -= shift_x;
		cords[i].y -= shift_y;
		i++;
	}
	data->ofset_x = 0;
	data->ofset_y = 0;
}

void	to_beginning(t_data *data, t_cords *cords)
{
	size_t	i;
	double	shift_x;
	double	shift_y;

	shift_x = data->cords[0].x;
	shift_y = data->cords[0].y;
	i = 0;
	while (i < data->pixels)
	{
		cords[i].x -= shift_x;
		cords[i].y -= shift_y;
		i++;
	}
	data->ofset_x = (int)(data->x_max * \
			(data->cords[data->x_max].x - data->cords[0].x) / 2);
	data->ofset_y = (int)(data->x_max * \
			(data->cords[data->y_max].y - data->cords[0].y) / 2);
}

void	to_previous(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->pixels)
	{
		data->cords[i].x += data->center_x;
		data->cords[i].y += data->center_y;
		i++;
	}
	data->ofset_x = data->center_x;
	data->ofset_y = data->center_y;
}

void	increase_z(t_data *data, int offset)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		if (data->start_cords[i].z - offset == 0)
			return ;
		if (data->start_cords[i].z != 0)
			data->start_cords[i].z += offset;
		i++;
	}
}

void	decrease_z(t_data *data, int offset)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		if (data->start_cords[i].z != 0)
		{
			if (data->start_cords[i].z - offset >= 1)
				data->start_cords[i].z -= offset;
		}
		i++;
	}
}
