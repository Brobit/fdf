/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:19:34 by almarico          #+#    #+#             */
/*   Updated: 2024/05/30 18:37:47 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(int keycode, t_window *mlx)
{
	(void)keycode;
	mlx_destroy_window(mlx->init_ptr, mlx->window);
	exit(0);
}

void	event_handler(t_window *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_handler, mlx);
	mlx_hook(mlx->window, ON_MOUSEDOWN, 1L << 6, closes, mlx);
}
