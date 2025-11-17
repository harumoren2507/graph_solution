/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:50:01 by retoriya          #+#    #+#             */
/*   Updated: 2024/05/10 19:47:58 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnt_size(unsigned int nbr, int base_len)
{
	int	size;

	size = 1;
	while (nbr / base_len)
	{
		size++;
		nbr /= base_len;
	}
	return (size);
}

char	*ft_itoa_base(unsigned int nbr, char *base)
{
	int		base_len;
	char	*str;
	int		size;

	base_len = ft_strlen(base);
	size = cnt_size(nbr, base_len);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = base[nbr % base_len];
		nbr /= base_len;
		size--;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	buffer[20];
	int		number;

	str = ft_itoa_base(1234, "0123456789abcdef");
	printf("%s\n", str);
	number = 1234;
	sprintf(buffer, "%x", number);
	printf("Hexadecimal: %s\n", buffer);
	return (0);
}
*/