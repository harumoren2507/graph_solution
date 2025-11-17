/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:13:43 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/17 13:04:37 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;

	start = s1;
	end = s1 + (ft_strlen(s1) - 1);
	while (*start && ft_trimset(*start, set))
		start++;
	while (end > start && ft_trimset(*end, set))
		end--;
	return (ft_substr(start, 0, end - start + 1));
}
/*
int	main(int argc, char *argv[])
{
	char	*trimmed_result;

	if (argc == 3)
	{
		trimmed_result = ft_strtrim(argv[1], argv[2]);
		printf("%s¥\n", trimmed_result);
		free(trimmed_result);
	}
	return (0);
}
*/