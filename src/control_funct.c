/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:20:34 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/05 14:54:20 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		increase(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	to_beginning(data, data->cords);
	to_beginning(data, data->start_cords);
	zoom_in(data, data->cords);
	zoom_in(data, data->start_cords);
	center_to_zero(data, data->cords);
	rotate(data, 0, 0, 0);
	to_previous(data);
}

void		decrease(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	to_beginning(data, data->cords);
	to_beginning(data, data->start_cords);
	zoom_out(data, data->cords);
	zoom_out(data, data->start_cords);
	center_to_zero(data, data->cords);
	rotate(data, 0, 0, 0);
	to_previous(data);
}

void		to_start_position(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 40, -30, 0);
	to_previous(data);
}

void		z_plus(t_data *data)
{
	increase_z(data, 10);
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 0, 0, 0);
	to_previous(data);
}

void		z_minus(t_data *data)
{
	decrease_z(data, 10);
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 0, 0, 0);
	to_previous(data);
}
