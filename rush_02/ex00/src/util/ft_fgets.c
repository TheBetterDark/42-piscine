/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmclaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:35:22 by cmclaren          #+#    #+#             */
/*   Updated: 2024/03/24 23:11:29 by cmclaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

char	*ft_fgets(char *s, int size, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (i < size - 1)
	{
		if (read(fd, &c, 1) <= 0)
		{
			return (NULL);
		}
		s[i++] = c;
		if (c == '\n')
		{
			break ;
		}
	}
	s[i] = '\0';
	return (s);
}
