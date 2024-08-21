/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:43:07 by mosokina          #+#    #+#             */
/*   Updated: 2024/03/10 22:09:29 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x_axis, int y_axis);

// Converts string to interger
int	str_to_int(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Only positive Intergers are accepted\n", 37);
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "Expects only 2 arguments\n", 26);
		return (0);
	}
	rush(str_to_int(argv[1]), str_to_int(argv[2]));
	return (0);
}
