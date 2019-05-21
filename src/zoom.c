/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:12:29 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/04 15:28:19 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_zoom(t_data *data)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		data->start_cords[i].x *= data->zoom;
		data->start_cords[i].y *= data->zoom;
		data->cords[i].x *= data->zoom;
		data->cords[i].y *= data->zoom;
		i++;
	}
}

void	zoom_in(t_data *data, t_cords *cords)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		cords[i].x *= 1.1;
		cords[i].y *= 1.1;
		cords[i].z *= 1.1;
		i++;
	}
	data->zoom += 1.1;
}

void	zoom_out(t_data *data, t_cords *cords)
{
	size_t		i;

	i = 0;
	while (i < data->pixels)
	{
		cords[i].x *= 0.9;
		cords[i].y *= 0.9;
		cords[i].z *= 0.9;
		i++;
	}
	data->zoom -= 1.1;
}
