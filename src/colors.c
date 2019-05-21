/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:42:10 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/05 17:48:02 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_red(t_data *data)
{
	data->blue = 0;
	data->green = 0;
	data->red = 255;
}

void		draw_green(t_data *data)
{
	data->blue = 0;
	data->green = 255;
	data->red = 0;
}

void		draw_blue(t_data *data)
{
	data->blue = 255;
	data->green = 0;
	data->red = 0;
}
