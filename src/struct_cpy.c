/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:58:02 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/04 15:26:02 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_struct(t_cords *dst_cords, t_cords *src_cords, t_data data)
{
	size_t i;

	i = 0;
	while (i < data.pixels)
	{
		dst_cords[i].x = src_cords[i].x;
		dst_cords[i].y = src_cords[i].y;
		dst_cords[i].z = src_cords[i].z;
		i++;
	}
}
