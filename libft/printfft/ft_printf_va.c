/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:49 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/28 21:49:19 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include "../libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf_va(int fd, const char *str, va_list *args)
{
	t_buff		out;
	int			ret;
	size_t		cursor;

	if (!str)
		return (-1);
	cursor = 0;
	ft_buff_init_str(&out, str);
	while (ft_bufffind(out.buff + cursor, "%", out.curr_size - cursor) != -1)
		ft_printf_parse(&out, &cursor, args);
	write(fd, out.buff, out.curr_size);
	ret = out.curr_size;
	ft_buff_destroy(&out);
	return (ret);
}
