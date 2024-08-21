/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:55:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/08/21 21:26:30 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c);

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_token;
	char		*token_start;

	last_token = NULL;
	if (str != NULL)
		last_token = str;
	else if (last_token == NULL)
		return (NULL);
	token_start = last_token;
	while (*token_start != '\0' && ft_strchr(delim, *token_start) != NULL)
		token_start++;
	if (*token_start == '\0')
	{
		last_token = NULL;
		return (NULL);
	}
	while (*last_token != '\0' && ft_strchr(delim, *last_token) == NULL)
		last_token++;
	if (*last_token != '\0')
	{
		*last_token = '\0';
		last_token++;
	}
	return (token_start);
}
