/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmclaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:01:18 by cmclaren          #+#    #+#             */
/*   Updated: 2024/03/24 23:02:16 by cmclaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

int	ft_group_three(char *str)
{
	int		group_three;
	int		len;

	group_three = 0;
	len = ft_strlen(str);
	while (len >= 3)
	{
		group_three += len % 3;
		len -= 3;
	}
	return (group_three);
	group_three = 0;
	len = ft_strlen(str);
	while (len >= 3)
	{
		group_three += len % 3;
		len -= 3;
	}
	return (group_three);
}
