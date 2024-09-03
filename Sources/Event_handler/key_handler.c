/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:03 by almarico          #+#    #+#             */
/*   Updated: 2024/09/03 11:24:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(t_pointer *pointer)
{
	mlx_destroy_window(pointer->mlx->init_ptr, pointer->mlx->window);
	free_map(pointer->map);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_pointer *pointer)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(pointer->mlx->init_ptr, pointer->mlx->window);
		free_map(pointer->map);
		exit(0);
	}
	return (0);
}
