/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:20:32 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/11 13:56:40 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(char *str)
{
	write(1, str, 3);
	if (str[0] != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	str[3];
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				str[0] = a;
				str[1] = b;
				str[2] = c;
				ft_print_digits(str);
				c++;
			}
			b++;
		}
		a++;
	}
}
