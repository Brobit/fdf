/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:35:18 by almarico          #+#    #+#             */
/*   Updated: 2024/06/02 13:59:03 by almarico         ###   ########.fr       */
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
}				t_window;

/* init display */
void	init_display(t_window *mlx);

/* display_loop */
void	display(t_window *mlx);

/* event handling */
void	event_handler(t_window *mlx);
int		key_handler(int keycode, t_window *mlx);
int		closes(t_window *mlx);

#endif
