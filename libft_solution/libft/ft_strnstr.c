/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:31:24 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/16 12:51:07 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] && (i + j < len) && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	const char	*haystack = "Hello, world!";
	const char	*needle1 = "world";
	const char	*needle2 = "Hello";
	const char	*needle3 = "!";
	const char	*needle4 = "test";
	char		*result;

	size_t len = 13; // テストの範囲を設定
	// needle1を検索
	result = ft_strnstr(haystack, needle1, len);
	if (result)
		printf("Found '%s' in '%s' -> %s\n", needle1, haystack, result);
	else
		printf("Did not find '%s' in '%s'\n", needle1, haystack);
	// needle2を検索
	result = ft_strnstr(haystack, needle2, len);
	if (result)
		printf("Found '%s' in '%s' -> %s\n", needle2, haystack, result);
	else
		printf("Did not find '%s' in '%s'\n", needle2, haystack);
	// needle3を検索
	result = ft_strnstr(haystack, needle3, len);
	if (result)
		printf("Found '%s' in '%s' -> %s\n", needle3, haystack, result);
	else
		printf("Did not find '%s' in '%s'\n", needle3, haystack);
	// needle4を検索
	result = ft_strnstr(haystack, needle4, len);
	if (result)
		printf("Found '%s' in '%s' -> %s\n", needle4, haystack, result);
	else
		printf("Did not find '%s' in '%s'\n", needle4, haystack);
	// 範囲を制限したテスト
	result = ft_strnstr(haystack, needle1, 5); // 範囲を'Hello'のみにする
	if (result)
		printf("Found '%s' in the first 5 chars of '%s' -> %s\n", needle1,
			haystack, result);
	else
		printf("Did not find '%s' in the first 5 chars of '%s'\n", needle1,
			haystack);
	return (0);
}
*/