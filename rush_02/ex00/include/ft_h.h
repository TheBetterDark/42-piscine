/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:38:26 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/24 22:50:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_find_value_to_key(const char *filename, char *entry);
char	*ft_strtok(char *str, const char *delim);
char	*ft_fgets(char *s, int size, int fd);
char	**ft_master_key_generator(char *str);
char	*ft_strchr(const char *str, int c);
char	**ft_key_two_hundred(char *str);
char	*ft_key_generate_hundred(void);
int		ft_strcmp(char *s1, char *s2);
char	*ft_key_generate_ten(char c);
char	**ft_key_three(char *str);
int		ft_group_three(char *str);
char	**ft_key_one(char *str);
char	**ft_key_two(char *str);
void	ft_putstr(char *str);
int		ft_row_len(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *str);
int		ft_check(char *str);
char	*ft_key(char c);

typedef struct t_pair
{
	char		*key;
	char		*value;
}	t_pair;

#define FT_H_H
#endif
