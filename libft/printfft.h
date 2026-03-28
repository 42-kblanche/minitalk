/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:12:35 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/25 02:03:22 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFFT_H
# define PRINTFFT_H

# ifndef PRINTF_OUT
#  define PRINTF_OUT 1
# endif

# include "buffft.h"
# include <stdarg.h>

typedef enum e_print
{
	PRINT_CHAR = 'c',
	PRINT_STRING = 's',
	PRINT_POINTER = 'p',
	PRINT_DECIMAL = 'd',
	PRINT_INTEGER = 'i',
	PRINT_UNSIGNED = 'u',
	PRINT_UPHEX = 'X',
	PRINT_LOHEX = 'x',
	PRINT_PERCENT = '%'
}	t_print;

int		ft_printf(const char *str, ...);
void	ft_printf_parse(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_char(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_string(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_pointer(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_integer(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_unsigned(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_uphex(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_lohex(t_buff *out, size_t *cursor, va_list *args);
void	ft_printf_parse_percent(t_buff *out, size_t *cursor);

#endif
