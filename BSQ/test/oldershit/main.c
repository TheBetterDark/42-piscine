/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasse <smasse@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:16:39 by smasse            #+#    #+#             */
/*   Updated: 2024/03/27 16:42:05 by smasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int fd;
	char buffer[1024];
    ssize_t bytes_read;
	// char *buffer;
	// t_map* maps;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "map error\n", 10);
			return (1);
		}
		while ((bytes_read = read(fd, buffer, 1024)) > 0)
		{
			// Process the read data
			//printf("%.*s", (int)bytes_read, buffer);
		}

		if (bytes_read == -1)
		{
			write(1, "map error\n", 10); 
			close(fd);
			return (1);
		}
		// maps[i-1].empty
		i++;
	}
}
