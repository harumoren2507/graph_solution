/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:35:10 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 08:18:20 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		src_len;
	char	*new_dest;

	i = 0;
	src_len = ft_strlen(str);
	new_dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (new_dest == NULL)
		return (NULL);
	while (str[i])
	{
		new_dest[i] = str[i];
		i++;
	}
	new_dest[i] = '\0';
	return (new_dest);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", ft_strdup(argv[1]));
	}
}
*/