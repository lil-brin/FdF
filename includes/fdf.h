/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:00:16 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/21 16:05:53 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
# define WIDTH 1280
# define HEIGHT 1024

typedef struct		s_cords_to_draw
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_cords_to_draw;

typedef struct		s_brezenhem
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_brezenhem;

typedef struct		s_cords
{
	double			x;
	double			y;
	double			z;
}					t_cords;

typedef struct		s_data
{
	t_cords_to_draw	cords_to_draw;
	t_cords			*start_cords;
	t_brezenhem		brezenhem;
	t_cords			*cords;
	double			zoom;
	int				x_max;
	int				y_max;

	int				ofset_x;
	int				ofset_y;

	int				center_x;
	int				center_y;

	char			*line_ptr;
	char			**cords_ptr;
	size_t			pixels;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*str_pixels;
	int				size_line;
	int				x_degree;
	int				y_degree;
	int				z_degree;
	int				red;
	int				green;
	int				blue;
	int				len;
	int				prev_len;

	int				flag;
	int				x;
	int				y;
	int				z;
}					t_data;

int					check_length(char **line);
int					count_new_lines(int fd);
void				cords_to_struct(t_data *data, int fd, \
	char *line_ptr, int length);
void				put_pix_on_image(int x, int y, t_data data);
char				*create_image(void *img_ptr, int *size_line);
int					exit_mouse(t_data *data);
int					manipulations(int key, t_data *data);
void				draw_all_lines(t_data *data);
void				draw_line(t_cords cords0, t_cords \
	cords1, t_data *data);
int					draw_line2(t_data *data);
void				to_center(t_data *data);
void				center_to_zero(t_data *data, \
	t_cords *cords);
void				copy_struct(t_cords *dst_cords, \
	t_cords *src_cords, t_data data);
void				to_beginning(t_data *data, t_cords *cords);
void				to_previous(t_data *data);
void				initialization(t_data *data);

void				move_right(t_data *data, int pixels);
void				move_left(t_data *data, int pixels);
void				move_up(t_data *data, int pixels);
void				move_down(t_data *data, int pixels);

void				first_zoom(t_data *data);
void				zoom_in(t_data *data, t_cords *cords);
void				zoom_out(t_data *data, t_cords *cords);

void				rotate_x(t_data *data, t_cords *cords, int offset);
void				rotate_y(t_data *data, t_cords *cords, int offset);
void				rotate_z(t_data *data, t_cords *cords, int offset);
void				rotate(t_data *data, int x, int y, int z);

void				increase_z(t_data *data, int offset);
void				decrease_z(t_data *data, int offset);
void				draw_image(t_data *data);

void				increase(t_data *data);
void				decrease(t_data *data);

void				rot_x(t_data *data);
void				rot_y(t_data *data);
void				rot_z(t_data *data);

void				draw_red(t_data *data);
void				draw_green(t_data *data);
void				draw_blue(t_data *data);

void				to_start_position(t_data *data);
void				z_plus(t_data *data);
void				z_minus(t_data *data);

void				rotations_moves(int key, t_data *data);
void				paint_z(t_data *data);
void				clean_data(t_data data);
#endif
