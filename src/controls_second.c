/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:12:46 by vmuravio          #+#    #+#             */
/*   Updated: 2018/03/29 14:12:47 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_x(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 5, 0, 0);
	to_previous(data);
}

void		rot_y(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 0, 5, 0);
	to_previous(data);
}

void		rot_z(t_data *data)
{
	copy_struct(data->cords, data->start_cords, *data);
	center_to_zero(data, data->cords);
	rotate(data, 0, 0, 5);
	to_previous(data);
}
