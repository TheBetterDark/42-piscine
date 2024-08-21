#include <stddef.h>
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

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

int	line_length(char *line)
{
	int	length;

	length = 0;
	while (line[length] != '\n' && line[length] != '\0')
		length++;
	printf("%d\n", length);
	return (length);
}
int	check_line_length(char *file)
{
	int		length;
	int		new_length;
	char	*line;

	length = -1;
	line = ft_strtok(file, "\n");
	line = ft_strtok(NULL, "\n");
	while (line != NULL)
	{
		new_length = line_length(line);
		if (length == -1)
		{
			length = new_length;
		}
		else if (length != new_length)
		{
			return (-1);
		}
		line = ft_strtok(NULL, "\n");
	}
	return (length);
}
