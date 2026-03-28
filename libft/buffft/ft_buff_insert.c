/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 07:12:56 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/27 21:31:29 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../buffft.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_buff_insert(t_buff *self, size_t index,
	const char *buff, size_t size)
{
	char	*tmp;

	if (!buff)
		return (0);
	if (self->curr_size < index)
		return (0);
	while (size > self->max_size - self->curr_size)
		ft_buff_double_size(self);
	tmp = ft_memdup(self->buff, self->max_size);
	if (!tmp)
	{
		free (tmp);
		return (0);
	}
	ft_memcpy(tmp + index, buff, size);
	ft_memcpy(tmp + index + size, self->buff + index, self->curr_size - index);
	free(self->buff);
	self->buff = tmp;
	self->curr_size += size;
	return (size);
}

size_t	ft_buff_insert_char(t_buff *self, size_t index, const char c)
{
	size_t	ret;

	ret = ft_buff_insert(self, index, &c, 1);
	return (ret);
}

size_t	ft_buff_insert_hex_lo(t_buff *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtolower(str);
	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	ft_buff_insert_hex_up(t_buff *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoh(n);
	ft_strtoupper(str);
	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	free(str);
	return (ret);
}
