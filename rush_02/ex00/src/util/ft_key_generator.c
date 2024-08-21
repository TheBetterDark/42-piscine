/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/06 16:13:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

char	**ft_master_key(int check, char **key_string, char *str)
{
	if (!key_string)
	{
		free(key_string);
		return (NULL);
	}
	else if (check == 1)
	{
		key_string = ft_key_one(str);
		return (key_string);
	}
	else if (check == 2)
	{
		key_string = ft_key_two(str);
		return (key_string);
	}
	else if (check == 3)
	{
		key_string = ft_key_three(str);
		return (key_string);
	}
	else if (check == 5)
	{
		key_string = ft_key_two_hundred(str);
		return (key_string);
	}
}

char	**ft_master_key_generator(char *str)
{
	int		len;
	int		check;
	char	**key_string;

	check = ft_check(str);
	len = ft_row_len(str);
	key_string = (char **)malloc((len + 1) * sizeof(char *));
	ft_master_key(check, key_string, str);
	if (!key_string)
	{
		ft_putstr("Error");
		free(key_string);
		return (NULL);
	}
	return (key_string);
}

char	*ft_key_generate_hundred(void)
{
	char	*key;

	key = (char *)malloc(4 * sizeof(char));
	if (!key)
	{
		ft_putstr("Error key generating fail");
		free(key);
		return (NULL);
	}
	key[0] = '1';
	key[1] = '0';
	key[2] = '0';
	key[3] = '\0';
	return (key);
}

char	*ft_key_generate_ten(char c)
{
	char	*key;

	key = (char *)malloc(3 * sizeof(char));
	if (!key)
	{
		ft_putstr("Error key generating fail");
		free(key);
		return (NULL);
	}
	key[0] = c;
	key[1] = '0';
	key[2] = '\0';
	return (key);
}
