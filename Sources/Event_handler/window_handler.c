/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:08:34 by almarico          #+#    #+#             */
/*   Updated: 2024/06/09 10:17:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	destroy_image(t_window *mlx)
{
	if (mlx->img.img_ptr)
	{
		mlx_destroy_image(mlx->init_ptr, mlx->img.img_ptr);
		mlx->img.img_ptr = NULL;
	}
}

void	redraw_window(t_window *mlx)
{
	destroy_image(mlx);
	image_handler(mlx);
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
}

int	window_handler(t_window *mlx)
{
	(void)mlx;
	return (SUCCESS);
}
