/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:22:22 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/24 23:22:28 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

/* 
This function is going to check if the string is more or equal to 3 lens. 
(If 3 and 1st chara is not 1) it means we need 1 more row for "hundred" key
*/
int	ft_row_len(char *str)
{
	int	row_size;

	row_size = ft_strlen(str);
	if (row_size % 3 == 0 && str[0] != '1')
		row_size += 1;
	return (row_size);
}
