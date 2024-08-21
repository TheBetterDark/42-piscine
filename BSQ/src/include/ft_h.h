/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:10:25 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:24:51 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;

	char	**grid;
	int		x;
	int		y;
}			t_map;

int			open_file(char *path);
char		*read_file(int fd);
int			free_file(char *buffer);
int			close_file(int fd);
void		print_grid(char **grid, int x_size, int y_size);
int			check_line_length(char *file);
int			check_line_length_part1(char *file, int *length);
int			check_line_length_part2(char *file, int length);
int			create_map_grid(t_map *t_map, char *file);
int			create_map_legend(t_map *t_map, char *file);
void		set_map_symbols(t_map *t_map, t_line *first_line, char *trun_line,
				char *second_line);
t_map		create_map(char *file);
void		free_map(t_map t_map, int lines_n);

// typedef	struct s_square
// {

// }	t_square;

#endif
