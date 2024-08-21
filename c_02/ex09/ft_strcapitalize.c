/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:24:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/03/17 21:58:27 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_charupcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	ft_charlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

int	ft_char_is_alpha(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (0);
	return (1);
}

int	ft_char_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_alpha(str[i]))
		{
			if (!ft_char_is_alpha(str[i - 1])
				&& !ft_char_is_numeric(str[i - 1]))
				ft_charupcase(&str[i]);
			else
				ft_charlowcase(&str[i]);
		}
		i++;
	}
	return (str);
}
