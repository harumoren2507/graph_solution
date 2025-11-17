/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:57:38 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/22 22:08:52 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

static int	get_wordcount(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count += 1;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*alloc_word(char const *start, char const *end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = *start;
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	split_word(char const *str, char **result, char c)
{
	char const	*start;
	char const	*end;
	int			i;

	i = 0;
	while (*str)
	{
		if (*str && *str == c)
			str++;
		start = str;
		while (*str && *str != c)
			str++;
		end = str;
		if (end > start)
		{
			result[i] = alloc_word(start, end);
			if (!result[i])
			{
				free_array(result, i);
				return ;
			}
			i += 1;
		}
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**result;

	if (s == NULL)
		return (NULL);
	wordcount = get_wordcount(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (result == NULL)
		return (NULL);
	split_word(s, result, c);
	return (result);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**words;
	int		i;

	i = 0;
	if (argc != 3)
	{
		printf("Usage: %s string charset\n", argv[0]);
		return (0);
	}
	words = ft_split(argv[1], argv[2][0]);
	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	if (words[i] == NULL)
		printf("NULL\n");
	free(words);
	return (0);
}
*/