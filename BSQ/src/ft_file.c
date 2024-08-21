/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:31:33 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:33 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_util.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	temp;
	int		bytes;
	int		buffer_size;

	buffer = NULL;
	bytes = 0;
	buffer_size = 0;
	while (read(fd, &temp, 1) > 0)
	{
		buffer = extend_buffer(buffer, &bytes, &buffer_size);
		if (!buffer)
			return (NULL);
		buffer[bytes++] = temp;
	}
	buffer = resize_buffer(buffer, bytes);
	return (buffer);
}

int	free_file(char *buffer)
{
	if (buffer)
	{
		free(buffer);
	}
	else
		return (0);
	return (1);
}

int	close_file(int fd)
{
	if (close(fd) < 0)
		return (0);
	return (1);
}
