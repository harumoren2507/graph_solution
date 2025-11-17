/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:49:43 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 08:17:52 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*combine;
	size_t	all_len;

	if (!s1 || !s2)
		return (NULL);
	all_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	combine = (char *)malloc(sizeof(char) * (all_len));
	if (!combine)
		return (NULL);
	ft_strlcpy(combine, s1, all_len);
	ft_strlcat(combine, s2, all_len);
	return (combine);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("usage %s <string1> <string2>\n", argv[0]);
		return (1);
	}
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
	return (1);
}
*/