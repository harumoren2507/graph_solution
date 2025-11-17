/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:01:04 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/17 14:03:13 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = 0;
	if (dest)
		dest_len = ft_strlen(dest);
	if (dest_size <= dest_len)
		return (dest_size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && i < dest_size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	size_t	dest_size;
	char	*dest;

	if (argc < 3)
	{
		printf("usage: %s <string1> <string2>\n", argv[0]);
		return (1);
	}
	dest_size = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1;
	dest = (char *)malloc(sizeof(char) * dest_size);
	if (dest == NULL)
		return (1);
	dest[0] = '\0';
	ft_strlcat(dest, argv[1], dest_size);
	ft_strlcat(dest, argv[2], dest_size);
	printf("%s\n", dest);
	free(dest);
}
*/