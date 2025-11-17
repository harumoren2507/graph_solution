/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:17:04 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 15:26:05 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}
/*
 int    main(void)
 {
	char str1[] = "ABCDEFK";
	char str2[] = "ABCDEFA";
	char str3[] = "ABCDEFKS";

	int result_ft = ft_memcmp(str1, str2, ft_strlen(str1));
	printf("ft_memcmp(str1 vs str2): %d\n", result_ft);

	result_ft = ft_memcmp(str1, str3, ft_strlen(str3));
	printf("ft_memcmp(str1 vs str3): %d\n", result_ft);

	int result_std = memcmp(str1, str2, ft_strlen(str1));
	printf("ft_memcmp(str1 vs str2): %d\n", result_std);

	result_std = memcmp(str1, str3, ft_strlen(str3));
	printf("ft_memcmp(str1 vs str3): %d\n", result_std);
 }
*/