/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_assign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:11:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/18 21:01:52 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stdlib.h>

void	ft_buff_assign(t_buff *self, const char *str)
{
	size_t	str_len;

	if (!str)
	{
		free(self->buff);
		self->buff = NULL;
		self->curr_size = 0;
		return ;
	}
	str_len = ft_strlen(str);
	while (self->max_size <= str_len)
		ft_buff_double_size(self);
	ft_memcpy(self->buff, str, str_len);
	self->curr_size = str_len;
}
