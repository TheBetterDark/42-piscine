/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:51:25 by smasse            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:10 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	line_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] != '\n' && line[length] != '\0')
		length++;
	return (length);
}
