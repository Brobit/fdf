/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:09 by almarico          #+#    #+#             */
/*   Updated: 2024/05/29 15:43:11 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Pilou");
	mlx_loop(mlx);
	(void)mlx_win;
	return (0);
}
