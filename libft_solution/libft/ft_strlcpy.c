/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:01:09 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/24 19:56:12 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	unsigned int	src_len;
	char			dest[2];
	unsigned int	Copied_len;

	if (argc < 2)
	{
		printf("usage: %s<string>\n", argv[0]);
		return (1);
	}
	src_len = ft_strlen(argv[1]);
	Copied_len = ft_strlcpy(dest, argv[1], sizeof(dest));
	printf("Original string: %s\n", argv[1]);
	printf("dest_size: %lu\n", sizeof(dest));
	printf("Copied dest: %s\n", dest);
	printf("Original length: %u\n", src_len);
	printf("Copied string length: %u\n", Copied_len);
	return (0);
}
*/