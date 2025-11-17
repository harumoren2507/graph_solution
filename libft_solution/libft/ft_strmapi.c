/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:59:03 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/17 12:12:20 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	ptr = ft_strdup(s);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
/*
char	upper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + i);
	return (c);
}

int	main(int argc, char *argv[])
{
	char	*result;

	if (argc == 2)
	{
		result = ft_strmapi(argv[1], upper);
		printf("%s\n", result);
	}
	return (0);
}
*/