/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:30:18 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/06 12:26:35 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotations_moves(int key, t_data *data)
{
	if (key == 2)
		move_right(data, 10);
	if (key == 0)
		move_left(data, 10);
	if (key == 13)
		move_up(data, 10);
	if (key == 1)
		move_down(data, 10);
	if (key == 126)
		rot_x(data);
	if (key == 125)
		rot_x(data);
	if (key == 124)
		rot_y(data);
	if (key == 123)
		rot_z(data);
	if (key == 53)
	{
		clean_data(*data);
		exit(0);
	}
}

int			manipulations(int key, t_data *data)
{
	if (key == 2 || key == 0 || key == 13 || key == 1 \
			|| key == 126 || key == 124 || key == 123 || key == 53)
		rotations_moves(key, data);
	if (key == 49)
		to_start_position(data);
	if (key == 30)
		increase(data);
	if (key == 33)
		decrease(data);
	if (key == 15)
		draw_red(data);
	if (key == 5)
		draw_green(data);
	if (key == 11)
		draw_blue(data);
	if (key == 24)
		z_plus(data);
	if (key == 27)
		z_minus(data);
	draw_image(data);
	return (0);
}

int			exit_mouse(t_data *data)
{
	clean_data(*data);
	exit(0);
}
