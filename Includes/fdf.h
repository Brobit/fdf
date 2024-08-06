/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:18 by almarico          #+#    #+#             */
/*   Updated: 2024/08/06 10:47:02 by almarico         ###   ########.fr       */
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
# define HEXADECIMAL_BASE			"0123456789ABCDEF"
# define ERR_ARGC					"./fdf <enter map path>\n"
# define ERR_FILE_FORMAT			"The map you want to open doesn't end with .fdf !\n"
# define ERR_STRUC_OR_DISPLAY_FAIL	"the initialisation of the display failed !\n"
# define ERR_FILE_OPENING			"the map opening doesn't succeed !\n"
# define ERR_TRANSFORM_TO_INT		"An error occured when transforming ascii to int\n"
# define ERR_MALLOC					"An error occured during the malloc\n"

/* mlx event define */
# define ON_KEYDOWN					2
# define ON_KEYUP					3
# define ON_MOUSEDOWN				4
# define ON_MOUSEUP					5
# define ON_MOUSEMOVE				6
# define ON_EXPOSE					12
# define ON_DESTROY					17

/* color define */
# define COLOR						0x000000
# define COLOR_RED					0xFF0000
# define COLOR_GREEN				0x00FF00
# define COLOR_BLUE					0x0000FF
# define COLOR_GREY					0x999999
# define DEFAULT_COLOR_VALUE		0xF000FF

# define COLOR_OCTANT_0				0xFFFFFF
# define COLOR_OCTANT_1				0xFFFF00
# define COLOR_OCTANT_2				0x9933FF
# define COLOR_OCTANT_3				0xFF0000
# define COLOR_OCTANT_4				0x66CCFF
# define COLOR_OCTANT_5				0x00FF33
# define COLOR_OCTANT_6				0x0066FF
# define COLOR_OCTANT_7				0x990033
# define COLOR_OCTANT_8				0x99CCFF

/* angle define in degre*/
# define ALPHA						35	// alpha is used to rotate verticaly
# define BETA						180	// beta is udes to rotate horizontally

/* sign and absolute value define */
# define ABS(_x)					((_x) >= 0 ? (_x) : -(_x))
# define SGN(_x)					((_x) < 0 ? -1 : ((_x) > 0 ? 1 : 0))

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

typedef struct s_map
{
	int				pos_x;
	int				pos_y;
	int				value;
	int				color;
}				t_map;

typedef struct s_map_info
{
	char			**map_info;
	t_map			**map;
	int				line_nb;
	int				line_size;
}				t_map_info;

typedef struct s_inner_interval
{
	int				min_horizontal;
	int				max_horizontal;
	int				min_vertical;
	int				max_vertical;
	int				horizontal_interval;
	int				vertical_interval;
	int				step_horizontal;
	int				step_vertical;
	int				offset_horizontal;
	int				offset_vertical;
	int				beggining_horizontal;
	int				beggining_vertical;
}				t_inner_interval;

/* init display */
int					init_display(t_window *mlx);

/* display_loop */
int					display(t_window *mlx, t_map_info *map);

/* event handling */
void				event_handler(t_window *mlx);
int					key_handler(int keycode, t_window *mlx);
int					closes(t_window *mlx);

/* image handling */
void				image_handler(t_window *mlx);
void				fill_image_with_pixel(t_window *mlx, t_map_info *map);

/* window handling */
int					window_handler(t_window *mlx);

/* file opening & map management*/
int					file_opener(const char *file, t_map_info *map);
int					transform_to_int(t_map_info *map);

/* utils */
void				write_message(const char *msg);
void				free_map_info(t_map_info *map);
void				free_map(t_map_info *map);
int					get_color_value(t_map_info *map);
int					file_checker(char *str);
int					check_coordonate(t_map *start, t_inner_interval *value_of);

/* color writing */
void				set_pixel_color(t_img_info img, int pos_x, int pos_y, int color);
void				draw_point(t_window *mlx, t_map_info *map);
void				draw_line(t_window *mlx, t_map_info *map, t_inner_interval *value_of);
void				fill_border_of_image(t_window *mlx);
t_inner_interval	set_interval_to_fill(t_window *mlx, t_map_info *map);

/* line utils */
void				draw_right_side(int start_x, int start_y, int end_x, int end_y, t_window *mlx);
void				draw_left_side(int start_x, int start_y, int end_x, int end_y, t_window *mlx);
void				draw_vertical(int start_x, int start_y, int end_y, t_window *mlx, char sign, int color);
void				draw_horizontal(int start_x, int start_y, int end_x, t_window *mlx, char sign, int color);
void				draw_octant_zero(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx);
void				draw_octant_one(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx);
void				draw_octant_two(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx);
void				draw_octant_three(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx);
void				draw_octant_four(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx);
void				draw_octant_five(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx);
void				draw_octant_six(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx);
void				draw_octant_seven(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx);

#endif
