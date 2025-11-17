/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:06:44 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 19:30:32 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	buffer[10] = "Hello";
	size_t	i;

	i = 0;
	printf("Before bzero:");
	while (i < sizeof(buffer))
	{
		printf("%u ", (unsigned char)buffer[i]);
		i++;
	}
	printf("\n");
	ft_bzero(buffer, sizeof(buffer));
	i = 0;
	printf("After bzero:");
	while (i < sizeof(buffer))
	{
		printf("%u ", (unsigned char)buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/