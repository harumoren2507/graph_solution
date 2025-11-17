/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:05 by retoriya          #+#    #+#             */
/*   Updated: 2025/01/20 06:14:06 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	all_handler(char fmt, va_list args)
{
	static t_fmt_handler	g_fmt_table[] = {{'c', ft_print_char}, {'s',
			ft_print_string}, {'p', ft_print_address}, {'d', ft_print_nbr},
			{'i', ft_print_nbr}, {'u', ft_print_unsign_nbr}, {'x',
			ft_print_lowhex}, {'X', ft_print_upperhex}, {'%', ft_print_percent},
			{0, NULL}};
	int						i;

	i = 0;
	while (g_fmt_table[i].spec != 0)
	{
		if (g_fmt_table[i].spec == fmt)
			return (g_fmt_table[i].func(args));
		i++;
	}
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		print_count;
	int		i;

	print_count = 0;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '\0')
				break ;
			print_count += all_handler(fmt[i], args);
		}
		else
		{
			write(1, &fmt[i], 1);
			print_count++;
		}
		i++;
	}
	va_end(args);
	return (print_count);
}
