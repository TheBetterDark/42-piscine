/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:38 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/06 16:13:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_h.h"

char	*ft_key(char c)
{
	char	*key;

	key = (char *)malloc(2 * sizeof(char));
	if (!key)
	{
		ft_putstr("Error key generating fail");
		free(key);
		return (NULL);
	}
	key[0] = c;
	key[1] = '\0';
	return (key);
}

char	**ft_key_one(char *str)
{
	char	**key_one;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(str);
	key_one = (char **)malloc(2 * sizeof(char));
	key_one[0] = (char *)malloc(3 * sizeof(char));
	key_one[0][0] = str[0];
	if (str[1] == '0')
	{
		key_one[0][j + 1] = '0';
		j++;
	}
	key_one[0][j + 1] = '\0';
	key_one[1] = NULL;
	return (key_one);
}

char	**ft_key_two_hundred(char *str)
{
	char	**key_two_hundred;
	int		len;
	int		j;

	j = 1;
	len = ft_strlen(str);
	key_two_hundred = (char **)malloc(3 * sizeof(char));
	key_two_hundred[0] = (char *)malloc(2 * sizeof(char));
	key_two_hundred[1] = (char *)malloc(38 * sizeof(char));
	key_two_hundred[0][0] = str[0];
	key_two_hundred[0][1] = '\0';
	key_two_hundred[1][0] = str[0];
	while (j < 37 && j <= (len - 1))
	{
		key_two_hundred[1][j] = '0';
		j++;
	}
	key_two_hundred[1][j] = '\0';
	key_two_hundred[2] = NULL;
	return (key_two_hundred);
}

char	**ft_key_two(char *str)
{
	char	**key_two;
	int		len;

	len = ft_row_len(str);
	key_two = (char **)malloc((len + 1) * sizeof(char));
	key_two[0] = ft_key_generate_ten(str[0]);
	key_two[1] = ft_key(str[1]);
	key_two[2] = NULL;
	return (key_two);
}

char	**ft_key_three(char *str)
{
	int		len;
	int		i;
	int		j;
	char	**key_string;

	len = ft_row_len(str);
	key_string = (char **)malloc((len + 1) * sizeof(char *));
	if (!key_string)
	{
		ft_putstr("Error");
		free(key_string);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (j < len)
	{
		key_string[j] = ft_key(str[i]);
		key_string[j + 1] = ft_key_generate_hundred();
		key_string[j + 2] = ft_key_generate_ten(str[i + 1]);
		key_string[j + 3] = ft_key(str[i + 2]);
		j += 4;
	}
	key_string[j] = NULL;
	return (key_string);
}
