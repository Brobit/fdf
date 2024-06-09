/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:09 by almarico          #+#    #+#             */
/*   Updated: 2024/06/09 10:05:55 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	init_structure(t_window *mlx)
{
	mlx->img.color = 0x00FF0000;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_window	mlx;

	(void)argc;
	(void)argv;
	if (init_structure(&mlx) == FAIL || init_display(&mlx) == FAIL)
		return (FAIL);
	display(&mlx);
	return (SUCCESS);
}
