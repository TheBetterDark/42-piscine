/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:49:52 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:35 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_util.h"
#include <stdio.h>
#include <stdlib.h>

void	print_grid(char **grid, int x_size, int y_size)
{
	int	y;
	int	x;

	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			ft_putchar(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int	check_line_length_part1(char *file, int *length)
{
	int		new_length;
	char	*line;
	char	*file_copy;

	*length = 0;
	file_copy = ft_strdup(file);
	if (file_copy == NULL)
		return (0);
	line = ft_strtok(file_copy, "\n");
	line = ft_strtok(NULL, "\n");
	while (line != NULL)
	{
		new_length = line_length(line);
		if (*length == 0)
			*length = new_length;
		else if (*length != new_length)
		{
			free(file_copy);
			return (0);
		}
		line = ft_strtok(NULL, "\n");
	}
	free(file_copy);
	return (1);
}

int	check_line_length_part2(char *file, int length)
{
	char	*line;
	char	*file_copy;

	file_copy = ft_strdup(file);
	if (file_copy == NULL)
		return (0);
	line = ft_strtok(file_copy, "\n");
	line = ft_strtok(NULL, "\n");
	while (line != NULL)
	{
		if (line[length - 1] != '\n')
		{
			free(file_copy);
			return (0);
		}
		line = ft_strtok(NULL, "\n");
	}
	free(file_copy);
	return (1);
}

int	check_line_length(char *file)
{
	int	length;

	if (!check_line_length_part1(file, &length))
		return (0);
	if (!check_line_length_part2(file, length))
		return (0);
	return (1);
}
