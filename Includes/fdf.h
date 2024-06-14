/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:18 by almarico          #+#    #+#             */
/*   Updated: 2024/06/14 12:49:25 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include "../libft-complete/get_next_line/gnl.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* general & error define */
# define SUCCESS					0
# define FAIL						1
# define STDIN						0
# define STDOUT						1	
# define STDERR						2
# define ERR_ARGC					"./fdf <enter map path>\n"
# define ERR_FILE_FORMAT			"The map you want to open doesn't end with .fdf !\n"
# define ERR_STRUC_OR_DISPLAY_FAIL	"the initialisation of the display failed !\n"
# define ERR_FILE_OPENING			"the map opening doesn't succeed !\n"
# define ERR_TRANSFORM_TO_FLOAT		"An error occured when transforming ascii to float\n"

/* mlx event define */
# define ON_KEYDOWN					2
# define ON_KEYUP					3
# define ON_MOUSEDOWN				4
# define ON_MOUSEUP					5
# define ON_MOUSEMOVE				6
# define ON_EXPOSE					12
# define ON_DESTROY					17

/* color define */
# define COLOR						0x00000000
# define COLOR_RED					0x00FF0000
# define COLOR_GREEN				0x0000FF00
# define COLOR_BLUE					0x000000FF

typedef struct s_img_info
{
	void			*img_ptr;
	char			*img_data_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_img_info;

typedef struct s_window
{
	void			*init_ptr;
	void			*window;
	int				width;
	int				height;
	t_img_info		img;
}				t_window;

typedef struct s_map_info
{
	char			**map_info;
	float			**map;
	size_t			line_nb;
	size_t			line_size;
}				t_map_info;

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
void	fill_image_with_pixel(t_window *mlx);
void	set_pixel_color(t_img_info img, int pos_x, int pos_y, int color);

/* window handling */
int		window_handler(t_window *mlx);

/* file opening */
int		file_opener(const char *file, t_map_info *map);

/* utils */
void	write_message(const char *msg);
void	free_char(t_map_info *map);
int		file_checker(char *str);

#endif
