/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:38:01 by mganchev          #+#    #+#             */
/*   Updated: 2024/08/21 21:26:21 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if ((*str >= 32 && *str <= 126) || *str == '\n')
			str++;
		else
			return (0);
	}
	return (1);
}
