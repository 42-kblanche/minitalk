/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:58:49 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/28 21:52:41 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printfft.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_errorf(const char *str, ...)
{
	va_list		args;
	int			ret;

	if (!str)
		return (-1);
	va_start(args, str);
	ret = ft_printf_va(STDERR_FILENO, str, &args);
	va_end(args);
	return (ret);
}
