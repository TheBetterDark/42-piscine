/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_one_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolagunj <oolagunj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:28:20 by olkoleos          #+#    #+#             */
/*   Updated: 2024/03/17 21:07:53 by oolagunj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Inputs 4 3 2 1 into the grid on the y-axis.
 '0' is for getting the correct character.
*/
void	input_grid_col(char **grid, int i, int size, int ascending)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (ascending)
			grid[j][i] = j + 1 + '0';
		else
			grid[j][i] = size - j + '0';
		j++;
	}
}

/*
 Inputs 4 3 2 1 into the grid on the x-axis.
 '0' is for getting the correct character.
*/
void	input_grid_row(char **grid, int i, int size, int ascending)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (ascending)
			grid[i][j] = j + 1 + '0';
		else
			grid[i][j] = size - j + '0';
		j++;
	}
}

/*
 Checks if the four_one rule applies on the grid on the y-axis.
*/
void	check_col(char **grid, char *hints, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (hints[i] == (size + '0') && hints[i + 8] == '1')
			input_grid_col(grid, i, size, 1);
		else if (hints[i] == (size + '1') && hints[i + 8] == '0')
			input_grid_col(grid, i, size, 0);
		i += 2;
	}
}

/*
 Checks if the four_one rule applies on the grid on the x-axis.
*/
void	check_row(char **grid, char *hints, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (hints[i + 16] == (size + '0') && hints[i + 24] == '1')
			input_grid_row(grid, i, size, 1);
		else if (hints[i + 17] == '1' && hints[i + 25] == (size + '0'))
			input_grid_row(grid, i, size, 0);
		i += 2;
	}
}

/*
 Helper function for checking if rule applies on grid.
*/
void	check_four_one_rule(char **grid, char *hints, int size)
{
	check_col(grid, hints, size);
	check_row(grid, hints, size);
}
