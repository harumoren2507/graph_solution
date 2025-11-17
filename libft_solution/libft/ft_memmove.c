/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:17:12 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/23 21:31:49 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr <= src_ptr)
		ft_memcpy(dest_ptr, src_ptr, n);
	else
	{
		while (n--)
		{
			dest_ptr[n] = src_ptr[n];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "abcdefg";

	ft_memmove(str1 + 2, str1, 3);
	printf("%s\n", str1);
	return (0);
}
*/