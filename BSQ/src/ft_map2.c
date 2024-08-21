/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:33:11 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:54 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_h.h"
#include <stdio.h>

char	**allocate_grid_memory(int rows, int cols)
{
	char	**grid;

	grid = malloc(sizeof(char *) * rows);
	if (grid == NULL)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	if (!allocate_grid_rows(grid, rows, cols))
	{
		return (NULL);
	}
	return (grid);
}

int	allocate_grid_rows(char **grid, int rows, int cols)
{
	int	y;

	y = 0;
	while (y < rows)
	{
		grid[y] = malloc(sizeof(char) * (cols + 1));
		if (grid[y] == NULL)
		{
			ft_putstr("map error\n");
			if (!free_grid_rows(grid, y))
				free(grid);
			return (0);
		}
		y++;
	}
	return (1);
}

int	free_grid_rows(char **grid, int limit)
{
	int	k;

	k = 0;
	while (k < limit)
	{
		free(grid[k]);
		k++;
	}
	return (1);
}

void	populate_grid_rows(t_map *t_map, char *file, int *i, int *y)
{
	int	x;

	x = 0;
	while (x < t_map->x && file[*i] != '\n' && file[*i] != '\0')
	{
		t_map->grid[*y][x] = file[*i];
		x++;
		(*i)++;
	}
	t_map->grid[*y][x] = '\0';
	(*y)++;
	if (file[*i] == '\n')
		(*i)++;
}
