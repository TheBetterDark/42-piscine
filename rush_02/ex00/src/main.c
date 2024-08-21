/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:37:07 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:27:27 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_h.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error: Invalid amount of arguments!\n");
		ft_putstr("Usage: ./rush-02 <number>\n");
		return (0);
	}
	ft_find_value_to_key("./dict/numbers.dict", argv[1]);
	return (0);
}
