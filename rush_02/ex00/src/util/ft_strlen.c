/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:22:04 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/24 23:22:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
	{
		ft_putstr("error");
		return (0);
	}
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
