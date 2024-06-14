/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:54:12 by almarico          #+#    #+#             */
/*   Updated: 2024/06/13 17:43:33 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	file_checker(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (FAIL);
	if ((str[i - 4] == '.') && (str[i - 3] == 'f') && (str[i - 2] == 'd') && (str[i - 1] == 'f'))
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

void	free_char(t_map_info *map)
{
	int	index;

	index = -1;
	while (++index < map->line_nb -1)
		free(map->map_info[index]);
	free(map->map_info);
}

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}
