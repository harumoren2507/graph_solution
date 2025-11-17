/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:21:26 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/24 22:04:05 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_pos;

	last_pos = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			last_pos = s;
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last_pos);
}
/*
int	main(void)
{
	char	str1[] = "xbcdeag";

	printf("%s\n", ft_strrchr(str1, 97));
	printf("%s\n", strrchr(str1, 97));
}
*/