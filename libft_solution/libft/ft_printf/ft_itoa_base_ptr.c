/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:29:57 by retoriya          #+#    #+#             */
/*   Updated: 2024/05/10 20:02:51 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnt_size(uintptr_t nbr, int base_len)
{
	int	size;

	size = 1;
	while (nbr / base_len != 0)
	{
		size++;
		nbr /= base_len;
	}
	return (size);
}

char	*ft_itoa_base_ptr(uintptr_t nbr, char *base)
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
