/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:15:35 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/21 16:03:46 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_data(t_data data)
{
	free(data.start_cords);
	free(data.cords);
	free(data.str_pixels);
	free(data.line_ptr);
}
