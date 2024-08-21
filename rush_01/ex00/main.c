/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolagunj <oolagunj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:28:20 by olkoleos          #+#    #+#             */
/*   Updated: 2024/03/17 21:08:12 by oolagunj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_four_one_rule(char **grid, char *hints, int size);
void	cleanup_grid(char **grid, int size);
void	print_grid(char **grid, int size);
char	**generate_grid(int size);

int	main(int argc, char	*argv[])
{
	char	*hints;
	char	**grid;

	if (argc != 2)
		return (0);
	hints = argv[1];
	grid = generate_grid(4);
	check_four_one_rule(grid, hints, 4);
	print_grid(grid, 4);
	cleanup_grid(grid, 4);
	return (0);
}
