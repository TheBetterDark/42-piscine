/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:31:33 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*extend_buffer(char *buffer, int *bytes, int *buffer_size)
{
	char	*new_buffer;

	if (*bytes >= *buffer_size)
	{
		*buffer_size += 1024;
		new_buffer = malloc(*buffer_size);
		if (!new_buffer)
		{
			free(buffer);
			return (NULL);
		}
		if (buffer)
		{
			ft_memcpy(new_buffer, buffer, *bytes);
			free(buffer);
		}
		buffer = new_buffer;
	}
	return (buffer);
}

char	*resize_buffer(char *buffer, int bytes)
{
	char	*resized_buffer;

	if (buffer)
	{
		buffer[bytes] = '\0';
		resized_buffer = malloc(bytes + 1);
		if (!resized_buffer)
		{
			free(buffer);
			return (NULL);
		}
		ft_memcpy(resized_buffer, buffer, bytes + 1);
		free(buffer);
		buffer = resized_buffer;
	}
	return (buffer);
}
