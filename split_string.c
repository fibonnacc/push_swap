/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:14:23 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:08:45 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			word = 0;
		}
		else if (word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
}

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**ft_split_fix(char const *s, char c, char **buffer)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			buffer[j] = ft_substr(s, start, i - start);
			if (!buffer[j])
				return (free_split(buffer), NULL);
			j++;
		}
	}
	buffer[j] = NULL;
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	buffer = malloc((count + 1) * sizeof(char *));
	if (!buffer)
	{
		free_split(buffer);
		return (NULL);
	}
	ft_split_fix(s, c, buffer);
	return (buffer);
}
