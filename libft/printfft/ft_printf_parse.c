/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:15:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/28 20:56:35 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#define NULL_STR "(null)"

void	ft_printf_parse(t_buff *out, size_t *cursor, va_list *args)
{
	char	tmp;

	*cursor += ft_bufffind(out->buff + *cursor, "%", out->curr_size - *cursor);
	tmp = out->buff[*cursor + 1];
	if (tmp == PRINT_CHAR)
		ft_printf_parse_char(out, cursor, args);
	else if (tmp == PRINT_STRING)
		ft_printf_parse_string(out, cursor, args);
	else if (tmp == PRINT_POINTER)
		ft_printf_parse_pointer(out, cursor, args);
	else if (tmp == PRINT_DECIMAL)
		ft_printf_parse_integer(out, cursor, args);
	else if (tmp == PRINT_INTEGER)
		ft_printf_parse_integer(out, cursor, args);
	else if (tmp == PRINT_UNSIGNED)
		ft_printf_parse_unsigned(out, cursor, args);
	else if (tmp == PRINT_UPHEX)
		ft_printf_parse_uphex(out, cursor, args);
	else if (tmp == PRINT_LOHEX)
		ft_printf_parse_lohex(out, cursor, args);
	else if (tmp == PRINT_PERCENT)
		ft_printf_parse_percent(out, cursor);
	else
		++*cursor;
}

void	ft_printf_parse_char(t_buff *out, size_t *cursor, va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_char(out, *cursor, c);
}

void	ft_printf_parse_string(t_buff *out, size_t *cursor, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	ft_buff_erase(out, *cursor, 2);
	if (str)
		*cursor += ft_buff_insert(out, *cursor, str, ft_strlen(str));
	else
		*cursor += ft_buff_insert(out, *cursor, NULL_STR, ft_strlen(NULL_STR));
}

void	ft_printf_parse_pointer(t_buff *out, size_t *cursor, va_list *args)
{
	void	*p;

	p = va_arg(*args, void *);
	ft_buff_erase(out, *cursor, 2);
	*cursor += ft_buff_insert_ptr(out, *cursor, p);
}
