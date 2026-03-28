/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:03:07 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/27 18:42:30 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

void	ft_buff_append(t_buff *self, const char *buff, size_t size)
{
	if (!buff)
		return ;
	if (!self->buff)
	{
		ft_buff_init_str(self, buff);
		return ;
	}
	while (self->curr_size > self->max_size - size)
		ft_buff_double_size(self);
	ft_memcpy(self->buff + self->curr_size, buff, size);
	self->curr_size += size;
}
