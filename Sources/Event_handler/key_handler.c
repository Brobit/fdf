/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:03 by almarico          #+#    #+#             */
/*   Updated: 2024/06/02 13:58:50 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(t_window *mlx)
{
	mlx_destroy_window(mlx->init_ptr, mlx->window);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_window *mlx)
{
	printf("%d\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->init_ptr, mlx->window);
		exit(0);
	}
	return (0);
}
