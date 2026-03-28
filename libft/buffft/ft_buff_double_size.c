/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_double_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:04:58 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/27 22:00:52 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stdlib.h>

size_t	ft_buff_double_size(t_buff *self)
{
	char	*temp;

	if (self->max_size == 0)
		self->max_size = 127;
	else
		self->max_size *= 2;
	temp = ft_calloc(self->max_size, 1);
	if (!temp)
	{
		free(self->buff);
		self->buff = NULL;
		self->max_size = 0;
		self->curr_size = 0;
		return (0);
	}
	if (self->buff && self->curr_size > 0)
		ft_memcpy(temp, self->buff, self->curr_size);
	free(self->buff);
	self->buff = temp;
	return (self->max_size);
}
