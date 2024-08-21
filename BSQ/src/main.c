/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:16:52 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:56 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_h.h"
#include "include/ft_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	find_largest_square(t_map *t_map, char **grid, int y, int x)
{
	int	**dp;
	int	max_size;
	int	max_index_i;
	int	min_prev;
	int	i;

	int max_index_j;:
	dp = malloc(y * sizeof(int *));
	i = 0;
	while (i < y)
	{
		dp[i] = malloc(x * sizeof(int));
		i++;
	}
	y = t_map->y;
	x = t_map->x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			dp[i][j] = 0;
		}
	}
	max_size = 0;
	max_index_i = 0;
	max_index_j = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (grid[i][j] == t_map->empty)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					min_prev = dp[i][j - 1];
					if (dp[i - 1][j] < min_prev)
						min_prev = dp[i - 1][j];
					if (dp[i - 1][j - 1] < min_prev)
						min_prev = dp[i - 1][j - 1];
					dp[i][j] = min_prev + 1;
				}
				if (dp[i][j] > max_size)
				{
					max_size = dp[i][j];
					max_index_i = i;
					max_index_j = j;
				}
			}
		}
	}
	for (int i = max_index_i - max_size + 1; i <= max_index_i; i++)
	{
		for (int j = max_index_j - max_size + 1; j <= max_index_j; j++)
		{
			grid[i][j] = t_map->full;
		}
	}
	// Free the memory allocated for dp
	for (int i = 0; i < y; i++)
	{
		free(dp[i]);
	}
	free(dp);
}

// TODO: check if every position after the first line is one of the characters in the legend

void	process_input(char *path)
{
	t_map	t_map;
	char	*file;
	int		fd;

	fd = open_file(path);
	file = read_file(fd);
	if (ft_str_is_printable(file) == 0)
	{
		ft_putstr("map error\n");
		free_file(file);
		close_file(fd);
		return ;
	}
	t_map = create_map(file);
	if (t_map.x == 0 || t_map.y == 0)
	{
		ft_putstr("map error\n");
		free_file(file);
		close_file(fd);
		return ;
	}
	find_largest_square(&t_map, t_map.grid, t_map.y, t_map.x);
	print_grid(t_map.grid, t_map.x, t_map.y);
	free_map(t_map, t_map.y);
	free_file(file);
	close_file(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		process_input_stdin();
	else
	{
		while (i < argc - 1)
		{
			process_input(argv[i + 1]);
			if (argc > 2 && i < argc - 2)
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
