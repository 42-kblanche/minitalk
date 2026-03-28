/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:45:09 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/27 19:26:51 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

void	ft_buff_erase(t_buff *self, size_t index, size_t len)
{
	ft_memcpy(self->buff + index,
		self->buff + index + len,
		self->curr_size - index - len
		);
	self->curr_size -= len;
}
