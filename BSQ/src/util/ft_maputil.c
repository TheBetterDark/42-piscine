/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:06:30 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:11 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_h.h"
#include "../include/ft_util.h"
#include <stdlib.h>

void	set_map_symbols(t_map *t_map, t_line *first_line, char *trun_line,
		char *second_line)
{
	t_map->full = first_line->line[first_line->len - 1];
	t_map->obstacle = first_line->line[first_line->len - 2];
	t_map->empty = first_line->line[first_line->len - 3];
	t_map->y = ft_atoi(trun_line);
	t_map->x = line_length(second_line);
}

int	symbols_are_valid(t_map *t_map)
{
	return (!(t_map->full == t_map->obstacle || t_map->full == t_map->empty
			|| t_map->obstacle == t_map->empty));
}

char	*truncate_line(char *first_line, int first_line_len)
{
	char	*truncated_line;

	truncated_line = malloc(first_line_len - 2 + 1);
	if (truncated_line != NULL)
	{
		ft_strncpy(truncated_line, first_line, first_line_len - 3);
		truncated_line[first_line_len - 3] = '\0';
	}
	else
	{
		free(truncated_line);
		return (NULL);
	}
	return (truncated_line);
}

void	free_stuff(char *truncated_line, char *file_copy)
{
	free(truncated_line);
	free(file_copy);
}
