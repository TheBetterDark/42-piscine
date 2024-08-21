/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:39:39 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/10 22:11:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// Handles the first line output
void	check_first_line(int x_axis, int x_count)
{
	if (x_count == 1)
		ft_putchar ('/');
	else if (x_axis == x_count)
		ft_putchar ('\\');
	else
		ft_putchar ('*');
}

// Handles the last line output
void	check_last_line(int x_axis, int x_count)
{
	if (x_count == 1)
		ft_putchar ('\\');
	else if (x_axis == x_count)
		ft_putchar ('/');
	else
		ft_putchar ('*');
}

// Handles the other lines output
void	check_other_axis(int x_axis, int x_count)
{
	if (x_count == 1 || x_count == x_axis)
		ft_putchar ('*');
	else
		ft_putchar (' ');
}

void	rush(int x_axis, int y_axis)
{
	int	y_count;
	int	x_count;

	if (x_axis <= 0 || y_axis <= 0)
		return ;
	y_count = 0;
	while (y_axis > y_count++)
	{
		x_count = 0;
		while (x_axis > x_count++)
		{
			if (y_count == 1)
				check_first_line(x_axis, x_count);
			else if (y_count == y_axis)
				check_last_line(x_axis, x_count);
			else
				check_other_axis(x_axis, x_count);
		}
		ft_putchar ('\n');
	}
}
