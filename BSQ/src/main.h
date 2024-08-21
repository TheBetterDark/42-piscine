/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:27:06 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:27:01 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void	maxindex(int max_index_i, int max_size, int max_index_j, char **grid,
			t_map *t_map);

void	freemem(int y, int **dp);
