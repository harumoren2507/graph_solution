/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 04:45:50 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/14 16:30:39 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	i;

	i = 0;
	while (i <= UCHAR_MAX)
	{
		if (ft_isdigit(i))
		{
			printf("%c(%d)\n", i, i);
		}
		i++;
	}
}
*/