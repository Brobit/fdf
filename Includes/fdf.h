/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:18 by almarico          #+#    #+#             */
/*   Updated: 2024/06/09 10:13:29 by almarico         ###   ########.fr       */
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
# include <X11/X.h>

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

typedef struct s_img_info
{
	void			*img_ptr;
	char			*img_data_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				color;
}				t_img_info;

typedef struct s_window
{
	void			*init_ptr;
	void			*window;
	int				width;
	int				height;
	t_img_info		img;
}				t_window;

/* init display */
int		init_display(t_window *mlx);

/* display_loop */
int		display(t_window *mlx);

/* event handling */
void	event_handler(t_window *mlx);
int		key_handler(int keycode, t_window *mlx);
int		closes(t_window *mlx);

/* image handling */
void	image_handler(t_window *mlx);
void	fill_image_with_pixel(t_img_info img, int pos_x, int pos_y, int color);

int		window_handler(t_window *mlx);

#endif
