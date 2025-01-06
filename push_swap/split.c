/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:54:59 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/06 15:22:26 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	s_len;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	substr = (char *)malloc(sizeof(*str) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start && j <= len)
			substr[j++] = str[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

static void	*free_all(char **split, size_t n)
{
	while (n--)
		free(split[n]);
	free(split);
	return (NULL);
}

static size_t	count_words(char *str, char delm)
{
	size_t	words;
	size_t	inside;

	inside = 0;
	words = 0;
	while (*str)
	{
		if (inside == 0 && *str != delm)
		{
			inside = 1;
			words++;
		}
		else if (*str == delm)
			inside = 0;
		str++;
	}
	return (words);
}

static size_t	get_pos(char *str, char delm)
{
	size_t pos;

	pos = 0;
	while (str[pos] && str[pos] != delm)
		pos++;
	return (pos);
}

char	**ft_split(char *str, char delm)
{
	size_t	counter;
	size_t	words;
	size_t	final;
	char	**split;

	if (!str)
		return (NULL);
	words = count_words(str, delm);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	counter = 0;
	while (counter < words)
	{
		while (*str && *str == delm)
			str++;
		final = get_pos(str, delm);
		split[counter] = ft_substr(str, 0, final);
		if (!split[counter])
			return (free_all(split, counter));
		str += final;
		counter++;
	}
	split[words] = NULL;
	return (split);
}