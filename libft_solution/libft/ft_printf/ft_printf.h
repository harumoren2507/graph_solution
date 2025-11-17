/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:48:00 by retoriya          #+#    #+#             */
/*   Updated: 2025/01/20 05:02:01 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef int			(*t_print_func)(va_list);

typedef struct s_fmt_handler
{
	char			spec;
	t_print_func	func;
}					t_fmt_handler;

int					ft_print_char(va_list args);
int					ft_print_string(va_list args);
int					ft_print_nbr(va_list args);
int					ft_print_unsign_nbr(va_list args);
char				*ft_itoa_base(unsigned int nbr, char *base);
char				*ft_itoa_base_ptr(uintptr_t nbr, char *base);
int					ft_print_upperhex(va_list args);
int					ft_print_lowhex(va_list args);
int					ft_print_address(va_list args);
int					ft_print_percent(va_list args);
int					ft_print_string2(char *str);
int					ft_printf(const char *format, ...);
#endif
