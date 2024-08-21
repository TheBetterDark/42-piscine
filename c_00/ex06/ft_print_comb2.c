/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:20:32 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/10 22:48:20 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digits(char a, char b)
{
	ft_putchar((a / 10) + '0');
	ft_putchar((a % 10) + '0');
	write(1, " ", 1);
	ft_putchar((b / 10) + '0');
	ft_putchar((b % 10) + '0');
	if (a != 98 || b != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_digits(a, b);
			b++;
		}
		a++;
	}
}
