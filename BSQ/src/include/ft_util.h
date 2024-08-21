/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:44:17 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:24:54 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include "./ft_h.h"

typedef struct s_line
{
	char	*line;
	int		len;
}			t_line;

int			ft_atoi(char *str);
int			line_length(char *line);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		*ft_memcpy(void *dst, const void *src, unsigned int n);
int			ft_str_is_numeric(char *str);
int			ft_str_is_printable(char *str);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *str, int c);
int			ft_strlen(char *str);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*truncate_line(char *first_line, int first_line_len);
int			symbols_are_valid(t_map *t_map);
void		set_map_symbols(t_map *t_map, t_line *first_line, char *trun_line,
				char *second_line);
void		free_stuff(char *truncated_line, char *file_copy);

#endif