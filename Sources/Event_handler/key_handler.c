/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:03 by almarico          #+#    #+#             */
/*   Updated: 2024/09/04 12:09:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(t_pointer *pointer)
{
	mlx_destroy_image(pointer->mlx->init_ptr, pointer->mlx->img.img_ptr);
	mlx_destroy_window(pointer->mlx->init_ptr, pointer->mlx->window);
	mlx_destroy_display(pointer->mlx->init_ptr);
	free(pointer->mlx->init_ptr);
	free_map(pointer->map);
	free(pointer);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_pointer *pointer)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(pointer->mlx->init_ptr, pointer->mlx->img.img_ptr);
		mlx_destroy_window(pointer->mlx->init_ptr, pointer->mlx->window);
		mlx_destroy_display(pointer->mlx->init_ptr);
		free(pointer->mlx->init_ptr);
		free_map(pointer->map);
		free(pointer);
		exit(0);
	}
	return (0);
}
