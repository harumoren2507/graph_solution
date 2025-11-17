/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:08:04 by retoriya          #+#    #+#             */
/*   Updated: 2024/05/09 12:27:03 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lowhex(va_list args)
{
	char	*str;
	int		nbr;
	char	*hex;
	int		lenght;

	nbr = va_arg(args, int);
	hex = "0123456789abcdef";
	lenght = 0;
	str = ft_itoa_base(nbr, hex);
	if (str == NULL)
		return (-1);
	lenght = ft_strlen(str);
	write(1, str, lenght);
	free(str);
	return (lenght);
}

int	ft_print_upperhex(va_list args)
{
	char	*str;
	int		nbr;
	char	*hex;
	int		lenght;

	nbr = va_arg(args, int);
	hex = "0123456789ABCDEF";
	lenght = 0;
	str = ft_itoa_base(nbr, hex);
	if (str == NULL)
		return (-1);
	lenght = ft_strlen(str);
	write(1, str, lenght);
	free(str);
	return (lenght);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%x\n", 1234);
// }
