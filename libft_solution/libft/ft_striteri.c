/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:00:05 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/23 22:32:47 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	upper(unsigned int	i, char *str)
{
	(void)i;
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_striteri(argv[1], upper);
		printf("%s\n", argv[1]);
	}
	return (0);
}
*/