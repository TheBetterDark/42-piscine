/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:13:59 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:51 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_h.h"
#include "include/ft_util.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	create_map_grid(t_map *t_map, char *file)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	if (file[i] == '\n')
		i++;
	if (!allocate_grid_memory(t_map, i))
		return (0);
	y = 0;
	while (y < t_map->y && file[i] != '\0')
	{
		populate_grid_rows(t_map, file, &i, &y);
	}
	if (y == 0)
		return (0);
	return (1);
}

int	create_map_legend(t_map *t_map, char *file)
{
	char	*truncated_line;
	char	*second_line;
	char	*file_copy;
	t_line	*first_line;

	file_copy = ft_strdup(file);
	if (file_copy == NULL)
		return (0);
	first_line->line = ft_strtok(file_copy, "\n");
	second_line = ft_strtok(NULL, "\n");
	first_line->len = line_length(first_line->line);
	if (first_line->len < 3)
	{
		free(file_copy);
		return (0);
	}
	truncated_line = truncate_line(first_line, first_line->len);
	set_map_symbols(t_map, first_line, truncated_line, second_line);
	if (truncated_line == NULL)
	{
		free(file_copy);
		return (0);
	}
	free_stuff(truncated_line, file_copy);
	return (1);
}

t_map	create_map(char *file)
{
	t_map	t_map;
	int		i;
	int		j;

	if (!create_map_legend(&t_map, file) || !create_map_grid(&t_map, file)
		|| !symbols_are_valid(&t_map))
		ft_putstr("map error\n");
	i = 1;
	while (i < t_map.y)
	{
		j = 0;
		while (j < t_map.x)
		{
			if (ft_strchr(map.legend, file[(i * (t_map.x + 1)) + j]) == NULL)
			{
				ft_putstr("map error\n");
				return (t_map);
			}
			j++;
		}
		i++;
	}
	return (t_map);
}

void	free_map(t_map t_map, int lines_n)
{
	int	i;

	i = 0;
	while (i < lines_n)
	{
		free(t_map.grid[i]);
		i++;
	}
	free(t_map.grid);
}
