/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:17:01 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 15:08:02 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s_ptr == (unsigned char)c)
			return (s_ptr);
		s_ptr++;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	char	buf[] = "ABCD35dhaa5aa";

	str = (char *)ft_memchr(buf, '5', sizeof(buf));
	if (str != NULL)
		printf("%s\n", str);
	else
		printf("Not Found\n");
	return (0);
}
*/