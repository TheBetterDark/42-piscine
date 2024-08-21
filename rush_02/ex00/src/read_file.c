/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:22:14 by cofische          #+#    #+#             */
/*   Updated: 2024/03/23 15:34:14 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_h.h"
#include <string.h>

// This function return array, it takes a const char and array as parameter :(
char *ft_find_value_to_key(const char *filename, char *entry)
{
	char **convert_entry;
	convert_entry = ft_master_key_generator(entry);

	int i;
	int j;
	i = 0;
	j = 0;

	int dict;
	char line[52];
	char *result = NULL;
	dict = open(filename, O_RDONLY);
	if (dict < 0)
	{
		ft_putstr("Error\n");
		free(convert_entry);
		return NULL;
	}
	t_pair *dictionary = malloc(52 * sizeof(t_pair));
	if (dictionary == NULL)
	{
		ft_putstr("Error\n");
		close(dict);
		free(dictionary);
		return NULL;
	}
	int dictionary_size = 0;
	while (ft_fgets(line, 52, dict) != NULL)
	{
		char *key = ft_strtok(line, ":");
		char *value = ft_strtok(NULL, ":");
		if (key != NULL && value != NULL)
		{
			dictionary[dictionary_size].key = strdup(key);
			dictionary[dictionary_size].value = strdup(value);
			dictionary_size++;
		}
	}
	while (convert_entry[i] != NULL)
	{
		j = 0;
		while (j < dictionary_size)
		{
			// printf("Comparing convert_entry[%d]: %s with dictionary[%d].key: %s\n", i, convert_entry[i], j, dictionary[j].key);
			if (ft_strcmp(convert_entry[i], dictionary[j].key) == 0)
			{
				printf("Key: %s, Value: %s", dictionary[j].key, dictionary[j].value);
				result = dictionary[j].value;
				break;
			}
			j++;
		}
		i++;
	}
	close(dict);
	if (result == NULL)
	{
		ft_putstr("Key not found\n");
	}
	i = 0;
	while (i < dictionary_size)
	{
		free(dictionary[i].key);
		free(dictionary[i].value);
		i++;
	}
	i = 0;
	while (convert_entry[i] != NULL)
	{
		free(convert_entry[i]);
		i++;
	}
	free(convert_entry);
	free(dictionary);
	return result;
}
