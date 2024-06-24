/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:01:16 by almarico          #+#    #+#             */
/*   Updated: 2024/06/18 13:29:22 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static int	count_line_in_file(const char *file, t_map_info *map)
{
	ssize_t	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (close(fd), FAIL);
	map->line_nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		map->line_nb++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (SUCCESS);
}

int	file_opener(const char *file, t_map_info *map)
{
	ssize_t	fd;
	int		index;

	if (count_line_in_file(file, map) == FAIL)
		return (FAIL);
	index = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	map->map_info = (char **)malloc((map->line_nb + 1) * sizeof(char *));
	if (!map->map_info)
		return (free_map_info(map), FAIL);
	map->map_info[map->line_nb] = NULL;
	while (index < map->line_nb)
	{
		map->map_info[index] = ft_strdup(get_next_line(fd));
		if (!map->map_info[index++])
			return (free_map_info(map), FAIL);
	}
	close(fd);
	index = 0;
	return (SUCCESS);
}
