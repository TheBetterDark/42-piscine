/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/14 00:57:00 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putarr(int *digits, int size)
{
	while (size > 0)
	{
		ft_putchar(digits[--size] + '0');
	}
}

void	ft_array_digits(int nb)
{
	int	digits[11];
	int	size;

	size = 0;
	while (nb > 0)
	{
		digits[size++] = nb % 10;
		nb /= 10;
	}
	ft_putarr(digits, size);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_array_digits(nb);
}
