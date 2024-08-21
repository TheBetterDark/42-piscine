/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:42:47 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/25 23:55:03 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*current_pos;
	char	*result;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	result = malloc(total_len);
	if (result == NULL)
		return (NULL);
	current_pos = result;
	i = 0;
	while (i < size)
	{
		ft_strcpy(current_pos, strs[i]);
		current_pos += ft_strlen(strs[i]);
		if (i < size - 1)
			current_pos += ft_strlen(ft_strcpy(current_pos, sep));
		i++;
	}
	*current_pos = '\0';
	return (result);
}
