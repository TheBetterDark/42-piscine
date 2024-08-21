/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmclaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:46:39 by cmclaren          #+#    #+#             */
/*   Updated: 2024/03/24 22:55:03 by cmclaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

int	ft_check_for_thousand(char *str)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	if (str[0] != '1')
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] != '0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check(char *str)
{
	int	len;
	int	result;

	result = ft_check_for_thousand(str);
	if (result == 1)
		return (5);
	len = ft_strlen(str);
	if (len == 0)
	{
		ft_putstr("error");
		return (0);
	}
	else if (len == 1)
		return (1);
	else if (len == 2)
	{
		if (str[1] == '0')
			return (1);
		return (2);
	}
	else if (len == 3)
		return (3);
	else if (len > 3)
		return (4);
	return (0);
}
