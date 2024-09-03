/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:54:12 by almarico          #+#    #+#             */
/*   Updated: 2024/09/03 16:08:02 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	free_map(t_map_info *map)
{
	int	i;

	i = 0;
	while (i < map->line_nb)
	{
		printf("%d\n", i);
		free(map->map_info[i]);
		free(map->map[i]);
		i++;
	}
}

int	file_checker(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (FAIL);
	if ((str[i - 4] == '.') && (str[i - 3] == 'f')
		&& (str[i - 2] == 'd') && (str[i - 1] == 'f'))
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}

int	get_color_value(t_map_info *map)
{
	while (**map->map_info >= '0' && **map->map_info <= '9')
		(*map->map_info)++;
	if (**map->map_info == ',' || **map->map_info == '.')
	{
		(*map->map_info += 3);
		return (ft_atoi_base(*map->map_info, HEXADECIMAL_BASE));
	}
	return (DEFAULT_COLOR_VALUE);
}
