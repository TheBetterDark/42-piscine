/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolagunj <oolagunj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:55:26 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/17 21:12:17 by oolagunj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

// Initialises the array with zeros
void	populate_grid(char **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = '0';
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	char **grid = generate_grid(4);
// 	grid[2][3] = 1;
// 	print_grid(grid, 4);
// 	cleanup_grid(grid, 4);
// 	return (0);
// }
// Generates the four dimensional array
char	**generate_grid(int size)
{
	char	**grid;
	int		i;

	i = 0;
	grid = (char **)malloc(size * sizeof(char *));
	while (i < size)
	{
		grid[i] = (char *)malloc(size * sizeof(char));
		i++;
	}
	populate_grid(grid, size);
	return (grid);
}

// Cleans up generated grid
void	cleanup_grid(char **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

// Prints the grid on screen
void	print_grid(char **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
