/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:49 by kblanche          #+#    #+#             */
/*   Updated: 2026/02/01 07:06:32 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_buff		out;
	int			ret;
	size_t		cursor;

	if (!str)
		return (-1);
	va_start(args, str);
	cursor = 0;
	ft_buff_init_str(&out, str);
	while (ft_bufffind(out.buff + cursor, "%", out.curr_size - cursor) != -1)
		ft_printf_parse(&out, &cursor, &args);
	write(PRINTF_OUT, out.buff, out.curr_size);
	ret = out.curr_size;
	ft_buff_destroy(&out);
	va_end(args);
	return (ret);
}
