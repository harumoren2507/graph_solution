/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdi_fmt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:43:46 by retoriya          #+#    #+#             */
/*   Updated: 2024/05/10 20:12:48 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	unsigned char	c;

	c = (unsigned char)(va_arg(args, int));
	return (write(1, &c, 1));
}

int	ft_print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_print_string2("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_string2(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_nbr(va_list args)
{
	int		nbr;
	char	*str;
	int		len;

	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	len = ft_print_string2(str);
	free(str);
	return (len);
}

int	ft_print_unsign_nbr(va_list args)
{
	unsigned int	nbr;
	char			*str;
	char			*base;
	int				len;

	nbr = va_arg(args, unsigned int);
	base = "0123456789";
	str = ft_itoa_base(nbr, base);
	if (!str)
		return (-1);
	len = ft_print_string2(str);
	free(str);
	return (len);
}
