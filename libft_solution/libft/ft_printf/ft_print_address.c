/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:57:37 by retoriya          #+#    #+#             */
/*   Updated: 2024/05/10 20:06:30 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(va_list args)
{
	char		*hex;
	char		*str;
	uintptr_t	nbr;
	int			length;

	nbr = va_arg(args, uintptr_t);
	hex = "0123456789abcdef";
	str = ft_itoa_base_ptr(nbr, hex);
	if (!str)
		return (-1);
	write(1, "0x", 2);
	length = ft_strlen(str);
	write(1, str, length);
	free(str);
	return (length + 2);
}
