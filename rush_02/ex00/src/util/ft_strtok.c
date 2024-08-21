/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:55:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/23 21:40:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_token = NULL;
	char		*token_start;

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
