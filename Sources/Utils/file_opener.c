/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:01:16 by almarico          #+#    #+#             */
/*   Updated: 2024/09/02 10:43:21 by almarico         ###   ########.fr       */
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

void	determinate_coef_part_two(t_map_info *map)
{
	if (ft_strcmp(PYLONE, map->name) == 0
		|| ft_strcmp(FIFTY_FOUR, map->name) == 0)
		map->coef = 10;
	else if (ft_strcmp(HUNDRED_SIX, map->name) == 0
		|| ft_strcmp(T2, map->name) == 0)
		map->coef = 5;
	else if (ft_strcmp(T1, map->name) == 0 || ft_strcmp(MARS, map->name) == 0)
		map->coef = 3;
	else if (ft_strcmp(ELEM_FRACT, map->name) == 0
		|| ft_strcmp(JULIA, map->name) == 0)
		map->coef = 1.1;
	else
		map->coef = 100;
}

void	determinate_coef(t_map_info *map)
{
	if (ft_strcmp(ELEM_COL, map->name) == 0 || ft_strcmp(ELEM, map->name) == 0
		|| ft_strcmp(BASICTEST, map->name) == 0)
		map->coef = 60;
	else if (ft_strcmp(TEN_TWO, map->name) == 0
		|| ft_strcmp(PLAT, map->name) == 0)
		map->coef = 40;
	else if (ft_strcmp(FORTY_TWO, map->name) == 0
		|| ft_strcmp(PNP_FLAT, map->name) == 0
		|| ft_strcmp(ELEM2, map->name) == 0)
		map->coef = 30;
	else if (ft_strcmp(PENTENEGPOS, map->name) == 0)
		map->coef = 28;
	else if (ft_strcmp(TEN_SEVENTY, map->name) == 0
		|| ft_strcmp(PYRA, map->name) == 0
		|| ft_strcmp(TWENTY_SIXTY, map->name) == 0
		|| ft_strcmp(PYRAMIDE, map->name) == 0)
		map->coef = 15;
	else
		determinate_coef_part_two(map);
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
	map->name = (char *)file;
	printf("%s\n", map->name);
	determinate_coef(map);
	return (SUCCESS);
}
