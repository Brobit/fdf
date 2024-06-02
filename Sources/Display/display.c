/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:45:42 by almarico          #+#    #+#             */
/*   Updated: 2024/06/02 13:43:21 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	init_display(t_window *mlx)
{
	mlx->init_ptr = mlx_init();
}

void	display(t_window *mlx)
{
	mlx->window = mlx_new_window(mlx->init_ptr, 1280, 720, "fdf");
	event_handler(mlx);
	mlx_loop(mlx->init_ptr);
}
