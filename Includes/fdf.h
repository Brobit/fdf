/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:18 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 18:17:31 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

# define SUCCESS					0
# define FAIL						1

/* mlx event define */
# define ON_KEYDOWN					2
# define ON_KEYUP					3
# define ON_MOUSEDOWN				4
# define ON_MOUSEUP					5
# define ON_MOUSEMOVE				6
# define ON_EXPOSE					12
# define ON_DESTROY					17

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	int		width;
	int		height;
}				t_window;

typedef struct s_img_info
{
	void	*img_ptr;
	char	*img_data_address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		color;
}				t_img_info;

/* init display */
int		init_display(t_window *mlx);

/* display_loop */
int		display(t_window *mlx, t_img_info *img);

/* event handling */
void	event_handler(t_window *mlx, t_img_info *img);
int		key_handler(int keycode, t_window *mlx, t_img_info *img);
int		closes(t_window *mlx);

/* image handling */
void	image_handler(t_window *mlx, t_img_info *img);
void	fill_image_with_pixel(t_img_info *img, int pos_x, int pos_y, int color);

#endif
