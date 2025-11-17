/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:58:00 by retoriya          #+#    #+#             */
/*   Updated: 2025/11/07 01:58:00 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_fprintf_format(int fd, char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), fd);
	}
	else if (format == 's')
	{
		ft_putstr_fd(va_arg(args, char *), fd);
	}
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), fd);
	}
	else if (format == '%')
	{
		ft_putchar_fd('%', fd);
	}
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				ft_fprintf_format(fd, *format, args);
		}
		else
		{
			ft_putchar_fd(*format, fd);
		}
		format++;
	}
	va_end(args);
	return (count);
}
